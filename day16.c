/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1 */
#include<stdio.h>
int main() 
{
    int n;
    scanf("%d",&n);
    int arr[n];
    // Read array
    for(int i = 0; i < n; i++) 
    scanf("%d", &arr[i]);

    // Step 1: Find maximum element
    int max = arr[0];
    for(int i = 1; i < n; i++) 
    {
        if(arr[i] > max) 
        {
            max = arr[i];
        }
    }

    // Step 2: Declare frequency array of size max+1
    int freq[max + 1];

    // Initialize frequency array to 0
    for(int i = 0; i <= max; i++) 
    freq[i] = 0;

    // Step 3: Count frequency
    for(int i = 0; i < n; i++) 
        freq[arr[i]]++;

    // Step 4: Print frequency (avoid duplicates)
    for(int i = 0; i < n; i++) {
        if(freq[arr[i]] != 0) {
            printf("%d:%d ", arr[i], freq[arr[i]]);
            freq[arr[i]] = 0;   // So we don’t print again
        }
    }

    return 0;
}
