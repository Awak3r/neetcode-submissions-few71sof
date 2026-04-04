class TimeMap:

    def __init__(self):
        self.base = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.base[key] = self.base.get(key, []) + [[value, timestamp]]
        self.base[key].sort(key=lambda x: x[1])

    def get(self, key: str, timestamp: int) -> str:
        if key in self.base.keys():
            cur = self.base[key]
        else:
            return ""
        a = 0
        b = len(cur) - 1
        while a<=b:
            mid = (a + b) // 2
            if cur[mid][-1] == timestamp:
                return cur[mid][0]
            elif cur[mid][-1] < timestamp:
                a = mid + 1
            else:
                b = mid - 1
        if b >= 0:
            return cur[b][0]
        return ""