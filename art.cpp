
#include "art.h"

//Name : Waleed Iqbal
//Description: This is the implemented art.cpp file which holds all the functions for use


Art::Art(){
    //This is the default constructor. It creates an empty object. An empty object does not hold any memory.
    //The constructor must initialize all member variables. The empty object has zero height and width.
    
    m_numColumns = 0;
    m_numRows = 0;
}

Art::Art(int rows, int columns){
    //This is the constructor. It initializes all member variables and it allocates required memory if neccessary. 
    //If the user passes invalid parameters such a a negative size the constructor creates an empty object.

    //checking for empty object
    if ((rows < 1) or (columns < 1))
    {
        m_numRows = 0;
        m_numColumns = 0;
        //initialize
        m_masterPiece = nullptr;
    }
    else
    {
        m_numColumns = columns;
        m_numRows = rows;
        //Allocate memory 
        m_masterPiece = new int* [rows];
        for(int i = 0; i < m_numRows; i++){
            m_masterPiece[i] = new int[m_numColumns];
            for(int j = 0; j < m_numColumns; j++){
                //initialize array of ints with 0's
                m_masterPiece[i][j] = 0; 
            }
        }
        

}
}

Art::~Art(){
    /*This is the destructor and it deallocates the memory.*/
    clear();


}

void Art::clear(){
    /*This function deallocates all memory and reinitializes all member variables to default values. It clears the current object to an empty object.*/
    
    for(int i = 0; i < m_numRows; i++){
        //delete each value
        delete[] m_masterPiece[i];
    }
    //delete array
    delete[] m_masterPiece;
    m_numRows = 0;
    m_numColumns = 0;
    m_masterPiece = nullptr;

}
    
    
    
    


void Art::create(int seed){
    /*This function generates random color code and inserts it into m_masterPiece. 
    To generate random code the function must create a Random object initialized for generating int numbers.
    Please note, you do not modify the Random class. You only use the Random class. 
    The parameter seed is the seed value to be used by the Random class.*/
    
    Random obj1(30,37);
    obj1.setSeed(seed);

    for(int i = 0; i < m_numRows; i++){
        for (int j = 0; j < m_numColumns; j++){
            //inserting random color code
            m_masterPiece[i][j] = obj1.getRandNum();
            
        }
    }
    
    
    
}


void Art::dumpColors(string pixel){
    if (m_numRows > 0 && m_numColumns > 0 && m_masterPiece != nullptr){
        for (int i=1;i <= m_numRows;i++){
            for (int j=1;j<=m_numColumns;j++){
                cout << "\033[1;" << to_string(m_masterPiece[i-1][j-1]) << "m" << pixel << pixel << "\033[0m";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void Art::dumpValues(){
    if (m_numRows > 0 && m_numColumns > 0 && m_masterPiece != nullptr){
        for (int i=1;i <= m_numRows;i++){
            for (int j=1;j<=m_numColumns;j++){
                cout << m_masterPiece[i-1][j-1] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

Art::Art(const Art& rhs){
    /*This is the copy constructor. It creates a deep copy of the rhs object. 
    Deep copy means the new object has its own memory allocated.*/
    m_numRows = rhs.m_numRows;
    m_numColumns = rhs.m_numColumns;

    m_masterPiece = new int* [m_numRows];//Allocate memory 

    for(int i = 0; i < m_numRows; i++){
        m_masterPiece[i] = new int[m_numColumns];
        for(int j = 0; j < m_numColumns; j++){
            //initialize with zeros
            m_masterPiece[i][j]=0; 
        }
    }
    for (int i = 0; i < m_numRows; i++){
        for (int j = 0; j < m_numRows; j++){
            //coppy the values from rhs onto masterpiece
            m_masterPiece[i][j] = rhs.m_masterPiece[i][j];
        }
        
    }
        
        
    

    
    
}

const Art& Art::operator=(const Art& rhs){
    //This is the assignment operator. It creates a deep copy of rhs and protects from self-assignment
        
    //check for self assignment
    if(this != &rhs){
        //Clearing out current object
        clear();
        m_numRows = rhs.m_numRows;
        m_numColumns = rhs.m_numColumns;
        
        //Allcoate memory
        m_masterPiece = new int* [m_numRows];

        for(int i = 0; i < m_numRows; i++){
            m_masterPiece[i] = new int[m_numColumns];

            for(int j = 0; j < m_numColumns; j++){
                //initialize values
                m_masterPiece[i][j]=0; 
            }
        }
        for (int i = 0; i < m_numRows; i++){
            for (int j = 0; j < m_numRows; j++){
                //Copy values
                m_masterPiece[i][j] = rhs.m_masterPiece[i][j];
            }
        
        }
        
    }
    return *this;
}

bool Art::appendToRight(const Art& rhs){
    /*This function appends the rhs object to the right of the current object. The append operation only happens if both objects have 
    the same height or either object is empty. 
    If the operation is successful the function returns true otherwise it returns false. The function allows for self-append, 
    an object can be appended to the right of itself. */
    
    
    int rows = m_numRows;
    int maxColumn = (m_numColumns + rhs.m_numColumns);//Total number of columns from both objects being appended
    //checking if both have the same height or if an object is empty
    if ((m_numRows == rhs.m_numRows)||((m_numRows == 0)&&(m_numColumns == 0))||((rhs.m_numRows == 0)&&(rhs.m_numColumns == 0))) {
        int** temp = new int * [m_numRows];
        for(int i = 0; i < m_numRows; i++){
            //creating a temp array of pointers with total amount of columns of both objects
            temp[i] = new int [maxColumn];
        }

        for(int i = 0; i < m_numRows; i++){
            //counter to increment through rhs columns
            int counter = 0;
            
            for(int j = 0; j < m_numColumns; j++) {
                //copy values of first half from masterpiece object onto temp array
                temp[i][j] = m_masterPiece[i][j];
            }
            for(int k = m_numColumns; k < maxColumn; k++){
                //copy values of second half from rhs object onto temp array
                //use counter to increment through the left over columns in rhs objects
                temp[i][k] = rhs.m_masterPiece[i][counter];
                counter++;
            }
        }
        //deallocate

        clear();
        m_numRows = rows;
        m_numColumns = maxColumn;
        m_masterPiece = temp;
        return true;

    }
    else{
        return false;
    }
}



bool Art::appendToBottom(const Art& bottom){
    /*This function appends the rhs object to the bottom of the current object. The append operation only happens 
    if both objects have the same width or either object is empty.
    If the operation is successful the function returns true otherwise it returns false. 
    The function allows for self-append, an object can be appended to the bottom of itself.
    */
    if (m_numColumns == bottom.m_numColumns or m_numColumns == 0 or bottom.m_numColumns == 0) {

        int col = bottom.m_numColumns;// bottom objects col
        int maxRow = (m_numRows + bottom.m_numRows);//Total amount of rows of both objects


        //creating a temp array of pointers with total amount of rows of both objects
        int** temp = new int * [maxRow];
        for (int i = 0; i < maxRow; i++) {
            temp[i] = new int [col];
        }
        //counter to increment through bottom object rows
        int counter = 0;
        for(int i = 0; i < maxRow; i++){
            
            if (i < m_numRows) {
                for(int k = 0; k < col; k++) {
                    //copy the first half values from masterpiece object onto the temp array
                    temp[i][k] = m_masterPiece[i][k];
                }
            }
            else{
            
                for (int j = 0; j < col; j++){
                    //copy the second half values from the bottom object onto the temp array
                    //use counter to increment through bottom object's rows once we have passed the amount of rows in the masterpiece object
                    temp[i][j] = bottom.m_masterPiece[counter][j];
                    
                }
                counter+=1;
                
            }   
            
        }
        //deallocate
        clear();
        m_numRows = maxRow;
        m_numColumns = col;
        m_masterPiece = temp;
        return true;
    }
    else {
        return false;
    }
}
