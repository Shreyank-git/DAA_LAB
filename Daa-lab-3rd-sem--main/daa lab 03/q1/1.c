#include<stdio.h>
// ----------------------------------binary search--------------------------------------
int binarysearch(int nums[],int key,int n){
    int st = 0,end = n-1;
    
     while( st <= end){
        int mid = st +(end - st)/2;
        if(nums[mid] == key ){
            return mid;
        }
        else if(nums[mid] < key){
            st = mid + 1;

        }
        else if(nums[mid] > key){
            end = mid -1;
        }
        else{
            printf("key value not found");
        }
    }
    return -1;
}
// -----------------------------------------------------------ternary search-------------------------------------------------- 
int ternarysearch(int nums[],int key,int n){
    int st = 0,end = n-1;
    

    while(st <= end){
        int mid1 = st + (end - st)/3,mid2 = mid1 +(end-st)/3;
        if(key == nums[mid1]){
            return mid1;
        }
        else if(key == nums[mid2]){
            return mid2;
        }
        else if(key < mid1){
            end = mid1 -1;
        }
        else if(key > mid2){
            st = mid2 +1;
        }
        else if(key>mid1 && key<mid2){
            st = mid1 +1;
            end = mid2 -1;
        }

    }
    return -1;
}


int main(){
int nums1[30] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};


//----------------------------------------------binary search operations---------------------------------------------
int key1 = 11;
int result = binarysearch(nums1 ,key1,30);

if (result == -1) {
    printf("Key not found");
}
else {
    printf("Key value %d found at index %d using binary search element\n",key1, result);
}

//---------------------------------------------ternary search operations--------------------------------------------
int key2 = 16;
int result1 = ternarysearch(nums1,key2,30);

if (result1 == -1) {
    printf("Key not found");
}
else {
    printf("Key value %d found at index %d using ternary  search element",key2, result1);
}

    return 0;
}


