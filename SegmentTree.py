from cmath import inf

class Query:
    def __init__(self,lo,hi) -> None:
        self.lo = lo
        self.hi = hi

class SegmentTree:
    def __init__(self,arr) -> None:
        self.segment_tree = {} #<indx,value>
        self.arr = arr

        #build segment tree over the input arr
        self.build(0,len(self.arr)-1,0)

    #lo,hi -> segment tree ranges
    #i -> segment tree index
    def build(self,lo,hi,i):
        #base case
        if lo==hi:
            self.segment_tree[i] = self.arr[lo]
            return

        m = (lo+hi)//2
        self.build(lo,m,2*i+1) #build left
        self.build(m+1,hi,2*i+2) #build right

        #find minimum in the range
        self.segment_tree[i] = min(\
            self.segment_tree[2*i+1],self.segment_tree[2*i+2])


    #find the minimum within range (lo,hi)
    def get(self,lo,hi,Q,i):
        #no overlap
        if hi<Q.lo or lo>Q.hi:
            return inf

        #complete overlap - range of node is part of the query range
        #<-Q.lo----|lo####hi|----Q.hi->
        if lo>=Q.lo and hi<=Q.hi:
            return self.segment_tree[i]

        #partial overlap
        m = (lo+hi)//2
        return min(
            self.get(lo,m,Q,2*i+1),
            self.get(m+1,hi,Q,2*i+2)
            )

    #new minimum after updating arr[arr_indx]
    #lo,hi -> segment tree ranges
    #i -> segment array index
    #arr_indx -> index in array
    def update(self,lo,hi,i,val,arr_indx):
        #reached index i
        if lo==hi:
            self.segment_tree[i] = val
            return

        m = (lo+hi)//2
        if arr_indx<=m:
            self.update(lo,m,2*i+1,val,arr_indx)
        else:
            self.update(m+1,hi,2*i+2,val,arr_indx)

        self.segment_tree[i] = min(
            self.segment_tree[2*i+1],
            self.segment_tree[2*i+2]
        )

arr = [1,7,3,8,2,6]
st = SegmentTree(arr)
print(st.segment_tree)
print("Minimum of range(3,5): ",st.get(0,len(arr)-1,Query(3,5),0))
st.update(0,len(arr)-1,0,9,4)
print("Minimum of range(3,5) after update: ",st.get(0,len(arr)-1,Query(3,5),0))