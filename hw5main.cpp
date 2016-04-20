#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void BubbleSort(const vector <int> inputVector, vector <int> &resultVector, int &compCount, int &swapCount);
void InsertionSort(const vector <int> inputVector, vector <int> &resultVector, int &compCount, int &swapCount);
void InnerQuickSort( vector <int> &resultVector,int left, int right, int &compCount, int &swapCount);
void QuickSort(const vector <int> inputVector, vector <int> &resultVector, int &compCount, int &swapCount);
void ShellSort(const vector <int> inputVector, vector <int> &resultVector, int &compCount, int &swapCount);
void Merge(vector <int> &resultVector, const int low, const int mid, const int high, int &compCount, int &swapCount);
void InnerMerge(vector <int> &resultVector, const int low, const int high, int &compCount, int &swapCount);
void MergeSort(const vector <int> inputVector, vector <int> &resultVector, int &compCount, int &swapCount);


int main()
{
	int compCount = 0;      //set a comparison counter set to 0 that will be passed into the sorting functions
	int swapCount = 0;      //set an exchange counter set to 0 that will be passed into the sorting functions
	vector <int> resultVector;      //set an empty vector of integers to store the results of the functions (will be passed by reference)
	
	ifstream input1;            //create an input file stream
	input1.open("Random.txt");  //set the input file to "Random.txt"
		
	if (!input1.is_open())      //if the file fails to open:
	{
		cout << "The file could not be found.\nCheck the location.\n";      //inform the user that the file is missing,
		return 0;                                                           //and exit the program
	}
		
		string line1 = "";                  //create an empty string variable
		vector<int> dataSetRandom;          //create a vector that will hold the input values from the Random file
                                            //and be passed into the functions thru the parameters
		while (getline(input1, line1))      //while there is information in the file:
		{
			istringstream iss1(line1);      //create an input string stream and add the data from the file
			int n;                          //create an integer variable to compare the string stream to

			while (iss1 >> n) //checks to make sure the data collected is an int (removes spaces from the file data)
			{
				dataSetRandom.push_back(n); //add the integer to the input vector
			}
		}
		
		input1.clear();         //clear the buffer
		input1.close();         //close Random.txt
		
		ifstream input2;            //repeat the actions of lines 25 thru 49 for the file "Reversed.txt" (lines 51-76)
		input2.open("Reversed.txt");
		
		if (!input2.is_open())
		{
			cout << "The file could not be found.\nCheck the location.\n";
			return 0;
		}
		
		string line2 = "";

		vector<int> dataSetReversed;

		while (getline(input2, line2))
		{
			istringstream iss2(line2);
			int n;

			while (iss2 >> n)
			{
				dataSetReversed.push_back(n);
			}
		}
		
		input2.clear();
		input2.close();
		
		ifstream input3;                    //repeat the actions of lines 25 thru 49 for the file "NearlySorted.txt" (lines 78-102)
		input3.open("NearlySorted.txt");
		
		if (!input3.is_open())
		{
			cout << "The file could not be found.\nCheck the location.\n";
			return 0;
		}
		
		string line3 = "";
		vector<int> dataSetNearly;

		while (getline(input3, line3))
		{
			istringstream iss3(line3);
			int n;

			while (iss3 >> n)
			{
				dataSetNearly.push_back(n);
			}
		}
		
		input3.clear();
		input3.close();
		
		ifstream input4;                   ////repeat the actions of lines 25 thru 49 for the file "FewUnique.txt" (lines 104-129)
		input4.open("FewUnique.txt");
		
		if (!input4.is_open())
		{
			cout << "The file could not be found.\nCheck the location.\n";
			return 0;
		}
		
		string line4 = "";
		vector<int> dataSetFew;

		while (getline(input4, line4))
		{
			istringstream iss4(line4);
			int n;

			while (iss4 >> n)
			{
				dataSetFew.push_back(n);
			}
		}
		
		input4.clear();
		input4.close();
        
        BubbleSort(dataSetRandom, resultVector, compCount, swapCount);              //perform functions on Random and display results
        cout << "The Results for 'Random.txt' Are: " << endl;
        cout << "Bubble Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;
        InsertionSort(dataSetRandom, resultVector, compCount, swapCount);          
        cout << "Insert Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;     
        QuickSort(dataSetRandom, resultVector, compCount, swapCount);               
        cout << "Quick Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;     
        ShellSort(dataSetRandom, resultVector, compCount, swapCount);           
        cout << "Shell Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;     
        MergeSort(dataSetRandom, resultVector, compCount, swapCount);               
        cout << "Merge Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;      
        
        BubbleSort(dataSetReversed, resultVector, compCount, swapCount);            //perform functions on Reversed and display results
        cout << "\nThe Results for 'Reversed.txt' Are: " << endl;                                       
        cout << "Bubble Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;    
        InsertionSort(dataSetReversed, resultVector, compCount, swapCount);         
        cout << "Insert Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;    
        QuickSort(dataSetReversed, resultVector, compCount, swapCount);            
        cout << "Quick Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;    
        
        ShellSort(dataSetReversed, resultVector, compCount, swapCount);           
        cout << "Shell Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;   
        
        MergeSort(dataSetReversed, resultVector, compCount, swapCount);         
        cout << "Merge Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;   
        
        BubbleSort(dataSetNearly, resultVector, compCount, swapCount);              //perform funtions on NearlySorted and display results
        cout << "\nThe Results for 'NearlySorted.txt' Are: " << endl;
        cout << "Bubble Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;
        InsertionSort(dataSetNearly, resultVector, compCount, swapCount);
        cout << "Insert Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;
        QuickSort(dataSetNearly, resultVector, compCount, swapCount);
        cout << "Quick Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;
        ShellSort(dataSetNearly, resultVector, compCount, swapCount);
        cout << "Shell Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;
        MergeSort(dataSetNearly, resultVector, compCount, swapCount);
        cout << "Merge Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;
        
        BubbleSort(dataSetFew, resultVector, compCount, swapCount);                 //perform functions on FewUnique and display results
        cout << "\nThe Results for 'FewUnique.txt' Are: " << endl;
        cout << "Bubble Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;
        InsertionSort(dataSetFew, resultVector, compCount, swapCount);
        cout << "Insert Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;
        QuickSort(dataSetFew, resultVector, compCount, swapCount);
        cout << "Quick Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;
        ShellSort(dataSetFew, resultVector, compCount, swapCount);
        cout << "Shell Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;
        MergeSort(dataSetFew, resultVector, compCount, swapCount);
        cout << "Merge Sort - Comparisons: " << compCount << ", Exchanges: " << swapCount << endl;
        
	return 0;       //return 0 to satisfy main() function type
}

void BubbleSort(const vector <int> inputVector, vector <int> &resultVector, int &compCount, int &swapCount)
{
	compCount = 0;              //sets the comparison counter, which is passed by reference, to 0
	swapCount = 0;              //sets the exchange counter, which is passed by reference, to 0

	resultVector = inputVector; //set the result vector to the input vector, both are passed by reference

	int temp;           //set a temporary int variable to cary the swapped values
	
	for (int i = 1; i < resultVector.size(); i++)   // For-loop to go through the individual locations in the vector (set at 1, so it doesn't compare a value to itself)
	{
		for (int j = 0; j < resultVector.size() - 1; j++)     //For-loop to go through the values
		{
			compCount++;                            //increase the comparison counter (for each iteration thru the for-loop)
			if (resultVector[j] > resultVector[j + 1]) //Compare two adjacent values in the vector, if the value following the current value is smaller:
			{
        		temp =resultVector[j];            //set the temp variable to the current value
				resultVector[j] = resultVector[j + 1]; //change the current element to the value of the next element (which is smaller)
				resultVector[j + 1] = temp;     //set the next element to the current element's original value
				swapCount++;                    //increase the swap counter by 1
			}
		}
	}
}

void InsertionSort(const vector <int> inputVector, vector <int> &resultVector, int &compCount, int &swapCount)
{
	compCount = 0;          //sets the comparison counter, which is passed by reference, to 0
	swapCount = 0;          //sets the exchange counter, which is passed by reference, to 0

	resultVector = inputVector;     //set the result vector to the input vector, both are passed by reference
	
	for (int i = 1; i < resultVector.size(); i++)   //go through the positions in the vector
	{
		int element = resultVector[i];    //set a holder variable to contain the element being moved/compared and set it to the current element in the for-loop
		int j = i;              //set another index variable to go through the "unsorted" portion of the vector
		
		
		while ((j > 0) && (resultVector[j - 1] > element)) //Compare the element of the "unsorted" portion to elements in the "sorted" portion, if the element being compared is smaller than the largest element in the sort portion:
		{
			compCount++;         //increment the comparison counter by 1
			resultVector[j] = resultVector[j - 1];      //move the the element to the position behind the element it was compared to (which is bigger)
			j --;           //decrement the index (to move out of the loop)
			swapCount++;    //increment the swap counter
		}
		resultVector[j] = element;      //move on to the next element
	}
}

void InnerQuickSort( vector <int> &resultVector,int left, int right, int &compCount, int &swapCount)
{
	int i = left, j = right;            //set an interger place for the left and right side of "the wall"
	int temp;                            //set a temp variable to hold moving values
	int pivot = resultVector[(left + right) / 2];       //set the pivot
	
	while (i <= j) {        //smaller values are on the left

		while (resultVector[i] < pivot)     //compares elements to the pivot, if the element is smaller:
		{
			i++;                // move the pivot's end location to the right
			compCount++;        //increment the comp count
		}	
		while (resultVector[j] > pivot)     //compares elements to the pivot, if the element is larger:
		{
			j--;                //move the pivot's location to the left of the element
			compCount++;        //increment the comp count
		}
			
		if (i <= j) {       
			temp = resultVector[i];          //if the current element is smaller than the pivot
			resultVector[i] = resultVector[j];  //swap the element with the one furthest to the left using temp
			resultVector[j] = temp;
			i++;                        //move the "walls"
			j--;
			swapCount++;                //increment the swap count
		}
	}

	if (left < j){
		InnerQuickSort(resultVector, left, j, compCount,swapCount);         //these 2  if statements determine which side of the wall to sort on
	}

	if (i < right){
		InnerQuickSort(resultVector, i, right, compCount, swapCount);
	}
}

void QuickSort(const vector <int> inputVector, vector <int> &resultVector, int &compCount, int &swapCount)
{
	compCount = 0;
	swapCount = 0;

	resultVector = inputVector;
	InnerQuickSort(resultVector, 0, resultVector.size() - 1, compCount, swapCount);
}

void ShellSort(const vector <int> inputVector, vector <int> &resultVector, int &compCount, int &swapCount)
{
	compCount = 0;      //set comp count to 0
	swapCount = 0;      //set swap count to 0

	resultVector = inputVector;     //copy the input data into the result vector

   int gap, i, j, temp;

    for (gap = resultVector.size()/2; gap > 0; gap /= 2){       //decrement the gap, but start at half the size of the vector
        for (i = gap; i < resultVector.size(); i++){        //compare elements
            compCount++;                                    //increment comp count
            for (j=i-gap; j>=0 && resultVector[j]>resultVector[j+gap]; j-=gap) {        //if the smaller value is on the left:
                temp = resultVector[j];                     //swap the values using temp
                resultVector[j] = resultVector[j+gap];
                resultVector[j+gap] = temp;
                swapCount++;                                //increment the swap count
            }
        }
    }
}

void Merge(vector <int> &resultVector, const int low, const int mid, const int high, int &compCount, int &swapCount)
{
	int * b = new int[high + 1 - low];      //make a new int array that holds the sorted values
	int h, i, j, k;
	h = low;
	i = 0;
	j = mid + 1;

	while ((h <= mid) && (j <= high))       //while there still numbers to compare in both original vectors (not really 2 vectors)
	{
		compCount++;                        //increment comp count
		if (resultVector[h] <= resultVector[j]) //compare elements in the "two original vectors" (actually the same vector)
		{
			b[i] = resultVector[h];     //add the lower value to the new sorted array
			h++;                        //move on to the next value in the vector that the last element came from
		}
		else
		{
			b[i] = resultVector[j];     //add lower value
			j++;                        //move on to next value
		}
		i++;                            //move onto next index in new array
	}

	if (h>mid)              //completes the new array and copies it into the original
	{
		for (k = j; k <= high; k++)
		{
			b[i] = resultVector[k];
			i++;
		}
	}
	else
	{
		for (k = h; k <= mid; k++)
		{
			b[i] = resultVector[k];
			i++;
		}
	}

	for (k = 0; k <= high - low; k++)
	{
		resultVector[k + low] = b[k]; 
		swapCount++;
	}
	delete[] b;         //deletes the new array after its been copied back
}

void InnerMerge(vector <int> &resultVector, int low, int high, int &compCount, int &swapCount)
{
	int mid;
	if (low < high)     //ensures parts of the vector that are being split are ordered
	{
		mid = (low + high) / 2;            //recursively separately the vector into two ordered vectors
		InnerMerge(resultVector, low, mid, compCount, swapCount);
		InnerMerge(resultVector, mid + 1, high, compCount, swapCount);
		Merge(resultVector, low, mid, high, compCount, swapCount);          //uses merge to merge the two sorted sections into one
	}
}
void MergeSort(const vector <int> inputVector, vector <int> &resultVector, int &compCount, int &swapCount)
{
	compCount = 0;      //set comp count to 0
	swapCount = 0;      //set swap count to 0

	resultVector = inputVector;     //copy input vector into result vector
	InnerMerge(resultVector, 0, resultVector.size() - 1, compCount, swapCount);     //use inner merge to sort two sections of the vector
}


