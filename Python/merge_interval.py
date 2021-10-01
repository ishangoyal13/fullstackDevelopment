# Given an array of intervals where intervals[i] = [starti, endi], 
# merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

def merge(intervals):
        if intervals==[]:
            return []
        result=[]
        intervals.sort()
        for interval in intervals:
            if result==[] or result[-1][1]<interval[0]:
                result.append(interval)
            else:
                result[-1][1]=max(result[-1][1],interval[1])
        return result

if __name__ == "__main__":
    intervals=[[1,3],[2,5]]
    print(merge(intervals))
