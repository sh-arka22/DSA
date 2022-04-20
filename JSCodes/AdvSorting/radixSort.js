/**
 * sorts the elements by first groupng the individual digits of the same place values
 */
function countSort(arr, decimal) {
    // const max = Math.max(...arr);

    let freq = new Array(10).fill(0);

    for(let i = 0; i < arr.length; i++) {
        freq[Math.floor(arr[i]/decimal)%10] += 1;
    }

    for(let i=1;i<freq.length;i++) {
        freq[i] += freq[i-1];
    }

    let res = new Array(arr.length).fill(0);

    for(let i = arr.length-1; i >= 0; i--) {
        res[freq[Math.floor(arr[i]/decimal)%10] - 1] = arr[i];
        freq[Math.floor(arr[i]/decimal)%10]--;
    }

    for(let i = 0; i< arr.length; i++){
        arr[i] = res[i];
    }
    return res;
}

function radixSort(arr){

    let max = Math.max(...arr);
    for(let decimal = 1; Math.floor(max/decimal)>0; decimal*=10){
        countSort(arr);
    }
}


let arr = [129, 431, 234, 653, 232, 824, 2, 291, 54];
radixSort(arr);