#include <stdio.h>
#include <stdlib.h>
#define IMAGE_SIZE 10
int beenThere[IMAGE_SIZE][IMAGE_SIZE];

// this function prints the array
void printImgArray(int array[IMAGE_SIZE][IMAGE_SIZE])
{

	printf("------ Image Contents -------\n");
	for (int i = 0; i < IMAGE_SIZE; i++)
	{
		for (int j = 0; j < IMAGE_SIZE; j++)
			printf("%02d, ", array[i][j]);
		printf("\n");
	}
	printf("-----------------------------\n");
}

void findCell(int setTo, int i, int j, int image[IMAGE_SIZE][IMAGE_SIZE]) //This method looks at the elements around the given coordinates to see if they are part of the cell
{																		  //it then updates beenThere to map out the places the cell is in by setting the respective coordinate to the value given in set
	if (i == 0)															  //All these if statements are here to make sure that no element outside of the range of image is accessed
	{
		if (j == 0)
		{
			for (int k = i; k <= i + 1; k++) //These for loops cycle around the element of the given coordinate to check if any of them are part of the same cell
			{
				for (int l = j; l <= j + 1; l++)
				{
					if (image[k][l] != 0 && beenThere[k][l] == 0) //check if it's part of the same cell
					{
						beenThere[k][l] = setTo;
						findCell(setTo, k, l, image); //recursively calls itself if it finds a new coordinate that's part of the cell so that coordinate can be scanned as well
					}
				}
			}
		}
		else if (j == IMAGE_SIZE - 1)
		{
			for (int k = i; k <= i + 1; k++) //These for loops cycle around the element of the given coordinate to check if any of them are part of the same cell
			{
				for (int l = j - 1; l <= j; l++)
				{
					if (image[k][l] != 0 && beenThere[k][l] == 0) //check if it's part of the same cell
					{
						beenThere[k][l] = setTo;
						findCell(setTo, k, l, image); //recursively calls itself if it finds a new coordinate that's part of the cell so that coordinate can be scanned as well
					}
				}
			}
		}
		else
		{
			for (int k = i; k <= i + 1; k++) //These for loops cycle around the element of the given coordinate to check if any of them are part of the same cell
			{
				for (int l = j - 1; l <= j + 1; l++)
				{
					if (image[k][l] != 0 && beenThere[k][l] == 0) //check if it's part of the same cell
					{
						beenThere[k][l] = setTo;
						findCell(setTo, k, l, image); //recursively calls itself if it finds a new coordinate that's part of the cell so that coordinate can be scanned as well
					}
				}
			}
		}
	}
	else if (i == IMAGE_SIZE - 1)
	{
		if (j == 0)
		{
			for (int k = i - 1; k <= i; k++) //These for loops cycle around the element of the given coordinate to check if any of them are part of the same cell
			{
				for (int l = j; l <= j + 1; l++)
				{
					if (image[k][l] != 0 && beenThere[k][l] == 0) //check if it's part of the same cell
					{
						beenThere[k][l] = setTo;
						findCell(setTo, k, l, image); //recursively calls itself if it finds a new coordinate that's part of the cell so that coordinate can be scanned as well
					}
				}
			}
		}
		else if (j == IMAGE_SIZE - 1)
		{
			for (int k = i - 1; k <= i; k++) //These for loops cycle around the element of the given coordinate to check if any of them are part of the same cell
			{
				for (int l = j - 1; l <= j; l++)
				{
					if (image[k][l] != 0 && beenThere[k][l] == 0) //check if it's part of the same cell
					{
						beenThere[k][l] = setTo;
						findCell(setTo, k, l, image); //recursively calls itself if it finds a new coordinate that's part of the cell so that coordinate can be scanned as well
					}
				}
			}
		}
		else
		{
			for (int k = i - 1; k <= i + 1; k++) //These for loops cycle around the element of the given coordinate to check if any of them are part of the same cell
			{
				for (int l = j - 1; l <= j + 1; l++)
				{
					if (image[k][l] != 0 && beenThere[k][l] == 0) //check if it's part of the same cell
					{
						beenThere[k][l] = setTo;
						findCell(setTo, k, l, image); //recursively calls itself if it finds a new coordinate that's part of the cell so that coordinate can be scanned as well
					}
				}
			}
		}
	}
	else
	{
		if (j == 0)
		{
			for (int k = i - 1; k <= i + 1; k++) //These for loops cycle around the element of the given coordinate to check if any of them are part of the same cell
			{
				for (int l = j; l <= j + 1; l++)
				{
					if (image[k][l] != 0 && beenThere[k][l] == 0) //check if it's part of the same cell
					{
						beenThere[k][l] = setTo;
						findCell(setTo, k, l, image); //recursively calls itself if it finds a new coordinate that's part of the cell so that coordinate can be scanned as well
					}
				}
			}
		}
		else if (j == IMAGE_SIZE - 1)
		{
			for (int k = i - 1; k <= i + 1; k++) //These for loops cycle around the element of the given coordinate to check if any of them are part of the same cell
			{
				for (int l = j - 1; l <= j; l++)
				{
					if (image[k][l] != 0 && beenThere[k][l] == 0) //check if it's part of the same cell
					{
						beenThere[k][l] = setTo;
						findCell(setTo, k, l, image); //recursively calls itself if it finds a new coordinate that's part of the cell so that coordinate can be scanned as well
					}
				}
			}
		}
		else
		{
			for (int k = i - 1; k <= i + 1; k++) //These for loops cycle around the element of the given coordinate to check if any of them are part of the same cell
			{
				for (int l = j - 1; l <= j + 1; l++)
				{
					if (image[k][l] != 0 && beenThere[k][l] == 0) //check if it's part of the same cell
					{
						beenThere[k][l] = setTo;
						findCell(setTo, k, l, image); //recursively calls itself if it finds a new coordinate that's part of the cell so that coordinate can be scanned as well
					}
				}
			}
		}
	}
}
/**
 * This function counts the number of distinct 
 * number (i.e. the number of cells)
 **/

int cellCount(int image[IMAGE_SIZE][IMAGE_SIZE])
{
	for (int i = 0; i < IMAGE_SIZE; i++) //resets the beenThere array
	{
		for (int j = 0; j < IMAGE_SIZE; j++)
		{
			beenThere[i][j] = 0;
		}
	}
	int cellCount = 0;					 //initailize cell count
	for (int i = 0; i < IMAGE_SIZE; i++) //cycles through all the elements in image
	{
		for (int j = 0; j < IMAGE_SIZE; j++)
		{
			if (image[i][j] != 0 && beenThere[i][j] == 0) //if the element in image is a cell and not already part of an already found cell, this triggers
			{
				cellCount++;
				beenThere[i][j] = 1;	  //mark that this cell has already been found
				findCell(1, i, j, image); // find the rest of the cell using findCell
			}
		}
	}
	return cellCount; //return the cellCount
}
/**
 * This function colors each cell with a unique color
 * (i.e. unique number)
 **/
void color(int image[IMAGE_SIZE][IMAGE_SIZE])
{
	for (int i = 0; i < IMAGE_SIZE; i++) //resets the beenThere array
	{
		for (int j = 0; j < IMAGE_SIZE; j++)
		{
			beenThere[i][j] = 0;
		}
	}
	int cellNum = 0; //initailize cell count number
	for (int i = 0; i < IMAGE_SIZE; i++)
	{
		for (int j = 0; j < IMAGE_SIZE; j++)
		{
			if (image[i][j] != 0 && beenThere[i][j] == 0) //if the element in image is a cell and not already part of an already found cell, this triggers
			{
				cellNum++;
				beenThere[i][j] = cellNum;		//mark that this cell with the appropriate number
				findCell(cellNum, i, j, image); // number the rest of the cell with the approriate number
			}
		}
	}
	for (int i = 0; i < IMAGE_SIZE; i++) //update all the elements in image to the ones in beenThere
	{
		for (int j = 0; j < IMAGE_SIZE; j++)
		{
			image[i][j] = beenThere[i][j];
		}
	}
}

/**
 * This function colors each cell with a unique color
 * (i.e., unique number). This function works with 
 * pointers
 * currentRow: shows the current row that is processed
 * currentCol: shows the current column that is process
 * currentIndex: show the index that is processed
 * color: is an integer that represents a color
 **/

int colorRecursively(int image[IMAGE_SIZE][IMAGE_SIZE], int currentRow, int currentCol, int currentIndex, int color)
{
	//tried and given up on this
}
void findCellPtr(int setTo, int index, int *image)
{
	if (index % IMAGE_SIZE == 0) //All these if statements are here to make sure that no element outside of the range of image is accessed
	{
		if (index < IMAGE_SIZE)
		{
			for (int i = index; i < index + IMAGE_SIZE + 2; i++) //this loop scans the elements around index to see if they are part of the same cell
			{
				if (*(image + i) != 0 && beenThere[i / IMAGE_SIZE][i % IMAGE_SIZE] == 0) //check if it's part of the same cell
				{
					beenThere[i / IMAGE_SIZE][i % IMAGE_SIZE] = setTo; //mark the found indexs with the same number as the rest of the cell
					*(image + i) = setTo;
					findCellPtr(setTo, i, image); //recursively calls itself if it finds a new index that's part of the cell so that coordinate can be scanned as well
				}
				if (i % IMAGE_SIZE == 1) //if i has reached the end of the scan range on the column switches to next row
				{
					i = i + 8;
				}
			}
		}
		else if (index > IMAGE_SIZE * IMAGE_SIZE - IMAGE_SIZE)
		{
			for (int i = index - IMAGE_SIZE; i < index + 2; i++) //this loop scans the elements around index to see if they are part of the same cell
			{
				if (*(image + i) != 0 && beenThere[i / IMAGE_SIZE][i % IMAGE_SIZE] == 0) //check if it's part of the same cell
				{
					beenThere[i / IMAGE_SIZE][i % IMAGE_SIZE] = setTo; //mark the found indexs with the same number as the rest of the cell
					*(image + i) = setTo;
					findCellPtr(setTo, i, image); //recursively calls itself if it finds a new coordinate that's part of the cell so that coordinate can be scanned as well
				}
				if (i % IMAGE_SIZE == 1) //if i has reached the end of the scan range on the column switches to next row
				{
					i = i + 8;
				}
			}
		}
		else
		{
			for (int i = index - IMAGE_SIZE; i < index + IMAGE_SIZE + 2; i++) //this loop scans the elements around index to see if they are part of the same cell
			{
				if (*(image + i) != 0 && beenThere[i / IMAGE_SIZE][i % IMAGE_SIZE] == 0) //check if it's part of the same cell
				{
					beenThere[i / IMAGE_SIZE][i % IMAGE_SIZE] = setTo; //mark the found indexs with the same number as the rest of the cell
					*(image + i) = setTo;
					findCellPtr(setTo, i, image); //recursively calls itself if it finds a new coordinate that's part of the cell so that coordinate can be scanned as well
				}
				if (i % IMAGE_SIZE == 1) //if i has reached the end of the scan range on the column switches to next row
				{
					i = i + 8;
				}
			}
		}
	}
	else if (index % IMAGE_SIZE == 9)
	{
		if (index < IMAGE_SIZE)
		{
			for (int i = index - 1; i < index + IMAGE_SIZE + 1; i++) //this loop scans the elements around index to see if they are part of the same cell
			{
				if (*(image + i) != 0 && beenThere[i / IMAGE_SIZE][i % IMAGE_SIZE] == 0) //check if it's part of the same cell
				{
					beenThere[i / IMAGE_SIZE][i % IMAGE_SIZE] = setTo; //mark the found indexs with the same number as the rest of the cell
					*(image + i) = setTo;
					findCellPtr(setTo, i, image); //recursively calls itself if it finds a new coordinate that's part of the cell so that coordinate can be scanned as well
				}
				if (i % IMAGE_SIZE == 9) //if i has reached the end of the scan range on the column switches to next row
				{
					i = i + 8;
				}
			}
		}
		else if (index > IMAGE_SIZE * IMAGE_SIZE - IMAGE_SIZE)
		{
			for (int i = index - IMAGE_SIZE - 1; i < index + 1; i++) //this loop scans the elements around index to see if they are part of the same cell
			{
				if (*(image + i) != 0 && beenThere[i / IMAGE_SIZE][i % IMAGE_SIZE] == 0) //check if it's part of the same cell
				{
					beenThere[i / IMAGE_SIZE][i % IMAGE_SIZE] = setTo; //mark the found indexs with the same number as the rest of the cell
					*(image + i) = setTo;
					findCellPtr(setTo, i, image); //recursively calls itself if it finds a new coordinate that's part of the cell so that coordinate can be scanned as well
				}
				if (i % IMAGE_SIZE == 9) //if i has reached the end of the scan range on the column switches to next row
				{
					i = i + 8;
				}
			}
		}
		else
		{
			for (int i = index - IMAGE_SIZE - 1; i < index + IMAGE_SIZE + 1; i++) //this loop scans the elements around index to see if they are part of the same cell
			{
				if (*(image + i) != 0 && beenThere[i / IMAGE_SIZE][i % IMAGE_SIZE] == 0) //check if it's part of the same cell
				{
					beenThere[i / IMAGE_SIZE][i % IMAGE_SIZE] = setTo; //mark the found indexs with the same number as the rest of the cell
					*(image + i) = setTo;
					findCellPtr(setTo, i, image); //recursively calls itself if it finds a new coordinate that's part of the cell so that coordinate can be scanned as well
				}
				if (i % IMAGE_SIZE == 9) //if i has reached the end of the scan range on the column switches to next row
				{
					i = i + 8;
				}
			}
		}
	}
	else
	{
		if (index < IMAGE_SIZE)
		{
			for (int i = index - 1; i < index + IMAGE_SIZE + 2; i++) //this loop scans the elements around index to see if they are part of the same cell
			{
				if (*(image + i) != 0 && beenThere[i / IMAGE_SIZE][i % IMAGE_SIZE] == 0) //check if it's part of the same cell
				{
					beenThere[i / IMAGE_SIZE][i % IMAGE_SIZE] = setTo; //mark the found indexs with the same number as the rest of the cell
					*(image + i) = setTo;
					findCellPtr(setTo, i, image); //recursively calls itself if it finds a new coordinate that's part of the cell so that coordinate can be scanned as well
				}
				if ((i % IMAGE_SIZE) == (index % IMAGE_SIZE) + 1) //if i has reached the end of the scan range on the column switches to next row
				{
					i = i + 7;
				}
			}
		}
		else if (index > IMAGE_SIZE * IMAGE_SIZE - IMAGE_SIZE)
		{
			for (int i = index - 11; i < index + 2; i++) //this loop scans the elements around index to see if they are part of the same cell
			{
				if (*(image + i) != 0 && beenThere[i / IMAGE_SIZE][i % IMAGE_SIZE] == 0) //check if it's part of the same cell
				{
					beenThere[i / IMAGE_SIZE][i % IMAGE_SIZE] = setTo; //mark the found indexs with the same number as the rest of the cell
					*(image + i) = setTo;
					findCellPtr(setTo, i, image); //recursively calls itself if it finds a new coordinate that's part of the cell so that coordinate can be scanned as well
				}
				if ((i % IMAGE_SIZE) == (index % IMAGE_SIZE) + 1) //if i has reached the end of the scan range on the column switches to next row
				{
					i = i + 7;
				}
			}
		}
		else
		{
			for (int i = index - IMAGE_SIZE - 1; i < index + IMAGE_SIZE + 2; i++) //this loop scans the elements around index to see if they are part of the same cell
			{
				if (*(image + i) != 0 && beenThere[i / IMAGE_SIZE][i % IMAGE_SIZE] == 0) //check if it's part of the same cell
				{
					beenThere[i / IMAGE_SIZE][i % IMAGE_SIZE] = setTo; //mark the found indexs with the same number as the rest of the cell
					*(image + i) = setTo;
					findCellPtr(setTo, i, image); //recursively calls itself if it finds a new coordinate that's part of the cell so that coordinate can be scanned as well
				}
				if ((i % IMAGE_SIZE) == (index % IMAGE_SIZE) + 1) //if i has reached the end of the scan range on the column switches to next row
				{
					i = i + 7;
				}
			}
		}
	}
}
void colorPtr(int *image)
{
	for (int i = 0; i < IMAGE_SIZE; i++) //resets the beenThere array
	{
		for (int j = 0; j < IMAGE_SIZE; j++)
		{
			beenThere[i][j] = 0;
		}
	}
	int cellNum = 0; //initailize cell count number
	for (int i = 0; i < IMAGE_SIZE * IMAGE_SIZE; i++)
	{
		if (*(image + i) != 0 && beenThere[i / 10][i % 10] == 0) //checks if the element is already part of a cell yet
		{
			cellNum++;
			beenThere[i / 10][i % 10] = cellNum; //mark the cell as found
			*(image + i) = cellNum;				 //change the number in image
			findCellPtr(cellNum, i, image);		 //mark the rest of the cell
		}
	}
}

#ifndef __testing
int main()
{

	// DO not change anything in main(), it will confuse the
	// auto-checker.
	puts("testing the code with color() function");
	int count = 0;
	int cellImg[IMAGE_SIZE][IMAGE_SIZE] = {{0, 0, 1, 1, 0, 0, 1, 0, 0, 1},
										   {1, 0, 1, 1, 0, 0, 1, 1, 0, 1},
										   {1, 0, 0, 1, 1, 0, 1, 1, 0, 1},
										   {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
										   {1, 0, 0, 1, 1, 1, 0, 0, 1, 0},
										   {0, 0, 0, 0, 1, 0, 0, 1, 1, 0},
										   {0, 0, 1, 0, 0, 1, 0, 1, 0, 0},
										   {0, 0, 1, 1, 0, 0, 1, 0, 0, 0},
										   {0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
										   {0, 1, 1, 0, 0, 0, 1, 1, 1, 1}};

	printImgArray(cellImg);
	color(cellImg);
	printImgArray(cellImg);
	count = cellCount(cellImg);
	printf("Total number of cells in the image: %d\n", count);

	puts("Testing the code with colorPtr");
	int cellImg_[IMAGE_SIZE][IMAGE_SIZE] = {{0, 0, 1, 1, 0, 0, 1, 0, 0, 1},
											{1, 0, 1, 1, 0, 0, 1, 1, 0, 1},
											{1, 0, 0, 1, 1, 0, 1, 1, 0, 1},
											{1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
											{1, 0, 0, 1, 1, 1, 0, 0, 1, 0},
											{0, 0, 0, 0, 1, 0, 0, 1, 1, 0},
											{0, 0, 1, 0, 0, 1, 0, 1, 0, 0},
											{0, 0, 1, 1, 0, 0, 1, 0, 0, 0},
											{0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
											{0, 1, 1, 0, 0, 0, 1, 1, 1, 1}};

	int *ptr = cellImg_;
	printImgArray(ptr);
	colorPtr(ptr);
	printImgArray(ptr);
	count = cellCount(ptr);
	printf("Total number of cells in the image: %d\n", count);
	puts("Testing the code with colorRecursively");
	int cellImg__[IMAGE_SIZE][IMAGE_SIZE] = {{0, 0, 1, 1, 0, 0, 1, 0, 0, 1},
											 {1, 0, 1, 1, 0, 0, 1, 1, 0, 1},
											 {1, 0, 0, 1, 1, 0, 1, 1, 0, 1},
											 {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
											 {1, 0, 0, 1, 1, 1, 0, 0, 1, 0},
											 {0, 0, 0, 0, 1, 0, 0, 1, 1, 0},
											 {0, 0, 1, 0, 0, 1, 0, 1, 0, 0},
											 {0, 0, 1, 1, 0, 0, 1, 0, 0, 0},
											 {0, 0, 1, 0, 0, 0, 0, 0, 1, 1},
											 {0, 1, 1, 0, 0, 0, 1, 1, 1, 1}};
	printImgArray(cellImg__);
	colorRecursively(cellImg__, 0, 0, 1, 0);
	printImgArray(cellImg__);
	count = cellCount(cellImg__);
	printf("Total number of cells in the image: %d\n", count);
	return 0;
}
#endif