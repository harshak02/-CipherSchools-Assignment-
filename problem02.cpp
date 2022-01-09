#include<iostream>
#include<vector>
using namespace std;

int elementRequired(int * ptr,int size,int target){

    int result;
    vector <int> vec1;

    for(int i = 0;i<size;i++){
        for(int j = i;j<size;j++){
            for(int k = j;k<size;k++){
                int temp = (*(ptr+i) + *(ptr+j) + *(ptr+k));
                vec1.push_back(temp);
            }
        }
    }

    int min = 1000;

    vector <int> vec2;

    for(int i = 0;i<vec1.size();i++){
        vec2.push_back(vec1[i]-target);
    }

    for(int i = 0;i<vec2.size();i++){
        if(min > vec2[i] && vec2[i] > 0){
            min = vec2[i];
        }
    }

    int j = 0;
    for(j;j<vec2.size();j++){
        if(min == vec2[j]){
            break;
        }
    }

    result = vec1[j];

    return result;
}

int main(){

    //create an input Array
    int size;

    cout<<"Enter the size of the array"<<endl;
    cin>>size;

    int arr[size];

    int target;

    cout<<"Enter the target of the array"<<endl;
    cin>>target;

    for(int i = 0;i<size;i++){
        int temp;
        cout<<"Enter the element no. "<<i+1<<endl;
        cin>>temp;
        arr[i] = temp;
    }

    int *ptr = arr;

    int result;
    result = elementRequired(ptr,size,target);

    cout<<"The element nrequired is "<<result<<endl; 
    return 0;
}
