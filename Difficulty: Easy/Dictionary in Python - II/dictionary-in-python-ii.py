def pair_sum(arr, sum):
    # code here
    add = {}
    for i in range(len(arr)):
        add[sum - arr[i]] = arr[i]
    for i in range(len(arr)):
        if arr[i] == (sum / 2) and (sum % 2) == 0:
            if (arr.count(arr[i]) > 1):
                return True
        elif arr[i] in add:
            return True
    return False
