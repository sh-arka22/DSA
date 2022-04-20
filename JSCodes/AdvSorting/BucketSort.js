// const bucketSort = (arr,numberOfBuckets) => {

// }

const res = function bucketSort(arr,numberOfBuckets) {
    let buckets = new Array(numberOfBuckets);

    for(let i = 0; i < numberOfBuckets; i++){
        buckets[i] = [];
    }

    for(let i = 0; i < arr.length; i++){
        let idx = Math.floor(10*arr[i]);
        buckets[idx].push(arr[i]);
    }

    //going into each and every bucket and than sorting them all each by each bucket
    for(let i = 0; i < numberOfBuckets; i++){
        buckets[i].sort();
    }

    //now combining each sorted bucketSort
    // let res = new Array(arr.length);
    let index = 0;

    for(let i = 0; i < buckets.length; i++){
        for(let j = 0; j < buckets[i].length; j){
            arr[index] = buckets[i][j];
            index ++;
        }
    }

    return arr;
}

let arr = [0.29, 0.34, 0.19, 0.39, 0.21, 0.41]
const numberOfBuckets = 10;
// let ans = bucketSort(arr,numberOfBuckets);
console.log( res(arr,numberOfBuckets));