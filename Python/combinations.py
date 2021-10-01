#code of combination in python

 def combine(self, n: int, k: int):
        self.result = []
        self.helper(1, n, k, [])
        return self.result
    
    def helper(self, start, end, k, path):
        if k == 0:
            self.result.append(path)
            return
        
        for i in range(start, end + 1):
            self.helper(i + 1, end, k - 1, path + [i])
