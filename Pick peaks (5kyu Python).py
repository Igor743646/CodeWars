def pick_peaks(arr):
    position = []
    peaks = []
    
    for i in range(1, len(arr)-1):
        if arr[i] > arr[i+1] and arr[i-1] < arr[i]:
            position.append(i)
            peaks.append(arr[i])
        elif arr[i] == arr[i+1]:
            s = 1
            while i+1+s < len(arr) and arr[i] == arr[i+1+s]:
                s+=1
            if i+1+s == len(arr):
                break
            if arr[i] > arr[i+1+s] and arr[i-1] < arr[i]:
                position.append(i)
                peaks.append(arr[i])
                i+=s

    return {"pos": position, "peaks": peaks}
