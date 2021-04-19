from suffix_trees import STree

#help(STree)

def init(n):
    array = []
    for i in range(1, n+1):
        path = "sample." + str(i)
        with open(path, 'rb') as file:
            data = file.read()
            array.append(str(data))
    return array

def get_lcs_between2(n, st):
    lcs = ""
    index1 = 0
    index2 = 0
    for i in range(0, n):
        for j in range(i, n):
            if i != j:
                temp = st.lcs(stringIdxs=[i, j])
                if len(temp) > len(lcs):
                    lcs = temp
                    index1 = i
                    index2 = j
    return (lcs, index1, index2)


def get_offset(n, lcs):
    offset = []
    for i in range(0, n):
        os = ar[i].find(lcs)
        offset.append(os)
    return offset

ar = init(10) #read into files
st = STree.STree(ar) #build suffix tree

lcs1 = st.lcs() #get lcs accorss all strings (for curiosity)
# print("Length of byte strands across all files ", len(lcs1), " ", lcs1)

lcs2, index1, index2 = get_lcs_between2(10, st) #actual longest strings between 2 files

offsets = get_offset(10, lcs2)
print("Length of most common strand %d" %len(lcs2))
print("File sample.%d offset at %d" % (index1+1, offsets[index1]))
print("File sample.%d offset at %d" % (index2+1, offsets[index2]))