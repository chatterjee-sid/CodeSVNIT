def Skyline(A):
	if not A:
		return []
	if len(A) == 1:
		return [[A[0][0], A[0][2]], [A[0][1], 0]]
	mid = len(A) // 2
	left = Skyline(A[:mid])
	right = Skyline(A[mid:])
	return merge(left, right)

def merge(left, right):
	h1, h2, res = 0, 0, []
	while left and right:
		if left[0][0] < right[0][0]:
			pos, h1 = left[0]
			left = left[1:]
		elif left[0][0] > right[0][0]:
			pos, h2 = right[0]
			right = right[1:]
		else:
			pos, h1 = left[0]
			h2 = right[0][1]
			left = left[1:]
			right = right[1:]
		H = max(h1, h2)
		if not res or H != res[-1][1]:
			res.append([pos, H])
	if left:
		res += left
	if right:
		res += right
	return res

L = [[33,41,5],[4,9,21],[30,36,9],[14,18,11],[2,12,14],[34,43,19],[23,25,8],[14,21,16],[32,37,12],[7,16,7],[24,27,10]]

print(Skyline(L))