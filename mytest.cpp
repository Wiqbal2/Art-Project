// UMBC - CMSC 341 - Fall 2022 - Proj0
#include "art.h"

class Tester{
    public:
    // the following is implemented as an example of measurement
    void measureInsertionTime(int numTrials, int inputSize);
    // the following tests the normal case of create() function
    bool testCreateNormal(Art & art);

    /******************************************
    * Test function declarations go here! *
    ******************************************/
   // Creating an art object as an error case
   bool testCreateError(Art & art);
   // Creating an art object as an edge case
   bool testCreateEdge(Art & art);

   //Tests copy cnstructor for a normal case
   bool testCopyConstructorNormal();

   //Tests copy constructor for a edge case
   bool testCopyConstructorEdge();

    //Tests Assignment Operator for normal
    bool testOperatorNormal( Art& rhs);
    // Tests Assignment Operator For Edge
    bool testOperatorEdge(Art &art);
    //Tests Append to right function for a normalcase
    bool TestAppendToRightNormal(Art &art);
    //Tests Append to right function for an errorcase
    bool TestAppendToRightError(Art &art);
    //Tests Append to right function for appending a normal object to an empty object, empty to normal object and itself
    bool TestAppendToRight();
    //Test append to bottom for a normal case
    bool TestAppendToBottomNormal();
    //Test append to bottom for an error case
    bool TestAppendToBottomError();
    //Tests Append to bottom function for appending a normal object to an empty object, empty to normal object and itself
    bool TestAppendToBottom();
};

int main(){
    
    Tester tester;// test object
    
    {
        // the following is a sample usage of the Art class
        // we create two objects and append them
        cout << "\nSample usage of the Art class:\n\n";
        Art art1(5,10);
        art1.create(10);
        cout << endl << "Dump of a 5x10 object:\n\n";
        art1.dumpColors("\u2588");// prints a box
        Art art2(5,15);
        art2.create(5);
        cout << endl << "Dump of a 5x15 object:\n\n";
        art2.dumpColors("\u2588");
        art1.appendToRight(art2);
        cout << endl << "Dump of the append result (5x25):\n\n";
        art1.dumpColors("\u2588");
        cout << endl << "Dump of the append result (5x25) values:\n\n";
        art1.dumpValues();
        
    }
    
    {
    // testing create function for normal case
    Art art(10,10);
    cout << "\nTesting the normal case of create function:\n\n";
    if (tester.testCreateNormal(art) == true)
        cout << "\tNormal case of create passed!\n";
    else
        cout << "\tNormal case of create failed!\n";
    }
    
    // testing create function for an Art object as an error case.
    Art art3(-1,10);
    cout<< "\nTesting the error case of create function:\n\n";
    if(tester.testCreateError(art3) == true){
        cout<<"\tError case of create passed!!\n";
    }
    else{
        cout<<"\tError case of create failed!!\n";
    }

    //testing the create function for an Art Object as an edge case
    Art art4(1,1);
    cout<< "\nTesting the edge case of create function:\n\n";
    if (tester.testCreateEdge(art4) == true){
        cout<<"\tEdge case of create passed!!\n";
    }
    else{
        cout<<"\tEdge case of create failed!!\n";
    }


    {
    // measuring the running time of insertion
    cout << "\nMeasuring the performance of insertion function:\n\n";
    // measuring the insertion of 100x100 colors, and 200x200 colors
    tester.measureInsertionTime(2,100);
    }

    //Testing the copy constructor for a normal case
    cout<< "\nTesting copy constructor for Normal Case\n\n";
    if (tester.testCopyConstructorNormal() == true){
        cout<<"\tNormal case of (All tests passed) copy constructor passed!!\n";
    }
    else {
        cout<<"\tNormal case of copy constructor failed!!\n";
    }

    //testting copy constuctor for edge case
    cout<< "\nTesting copy constructor for Edge Case(Empty object)\n\n";
    if (tester.testCopyConstructorEdge() == true){
        cout<<"\tEdge case of copy constructor passed!!\n";
    }
    else{
       cout<<"\tEdge case of copy constructor failed!!\n"; 
    }

    
    //Testing Assignment operator Normal case
    cout<<"\nTesting Assaignment Operator for normal Case\n\n";
    Art art8(10,10);
    if (tester.testOperatorNormal(art8) == true){
        cout<<"\tNormal case of Assignment operator passed"<<endl;
    }
    else{
        cout<<"\tNormal case of Assignment operator failed"<<endl;
    }



    //Testing Assignment operator edge case
    cout<<"\nTesting Assignment Operator for edge  Case\n\n";
    Art art10(0,0);
    art10.create(10);
    if (tester.testOperatorEdge(art10) == true){
        cout<<"\tedge case of Assignment operator passed(assigns an empty object correctly)"<<endl;
    }
    else{
        cout<<"\tedgecase of Assignment operator failed"<<endl;
    }

    
    //Testing append to right function for normal case
    cout<<"\nTesting Append to Right  for normal case"<<endl;
    Art art12(7,7);
    if (tester.TestAppendToRightNormal(art12) == true){
        cout<<"\tNormal case of Append to right passed"<<endl;
    }
    else{
        cout<<"\tNormal case of Append to right failed"<<endl;
    }

    //Testing append to right functions for error case
    cout<<"\nTesting Append to Right  for error case"<<endl;
    Art art14(10,10);
    if (tester.TestAppendToRightError(art14) == false){
        cout<<"\terror case of Append to right passed"<<endl;
    }
    else{
        cout<<"\terror case of Append to right failed"<<endl;
    }

    //Testing append to right function with normal objects, empty objects, and to self
    cout<<"\nTesting Append to right for appending a normal object to an empty object,"<<endl;
    cout<<"\nan empty object to a normal object, and appending object to itself"<<endl;
    if (tester.TestAppendToRight() == true){
        cout<<"\tAppend to right is working correctly for appending a normal object to an empty object."<<endl;
        cout<< "\tAppend to right is working correctly for appending an empty object to a normal object."<<endl;
        cout<<"\tAppend to right is working correctly for appending an object to itself."<<endl;
    }
    else{
        cout<<"\tAppend to right is not working correctly for appending a normal object to an empty object(Failed)."<<endl;
    }

    //Testing Append to bottom function for normal case
    cout<<"\nTesting Append to bottom function for normal case"<<endl;
    if (tester.TestAppendToBottomNormal() == true){
        cout<<"\tnormal case of Append to bottom passed"<<endl;
    }
    else{
        cout<<"\tnormal case of Append to bottom failed"<<endl;
    }

    //Testing append to bottom function for error case
    cout<<"\nTesting Append to bottom  for error case"<<endl;
    if (tester.TestAppendToBottomError() == false){
        cout<<"\terror case of Append to bottom passed"<<endl;
    }
    else{
        cout<<"\terror case of Append to bottom failed"<<endl;
    }

    //Testing append to right function with normal objects, empty objects, and to self
    cout<<"\nTesting Append to bottom for appending a normal object to an empty object"<<endl;
    cout<<"an empty object to a normal object, and appending object to itself"<<endl;
    if (tester.TestAppendToBottom() == true){
        
        cout<<"\tAppend to bottom is working correctly for appending a normal object to an empty object."<<endl;
        cout<< "\tAppend to bottom is working correctly for appending an empty object to a normal object."<<endl;
        cout<<"\tAppend to bottom is working correctly for appending an object to itself."<<endl;
    }
    else{
        cout<<"\tAppend to bottom is not working correctly for appending a normal object to an empty object(Failed)."<<endl;
    }
    

    return 0;
}



bool Tester::TestAppendToBottom(){
    //Testing append to right function with normal objects, empty objects, and to self
    bool result = true;
    Art art1(13,5);
    Art art2(0,0);
    
    if(art1.appendToBottom(art2) == true){
        //Appending an empty object to a normal object
        
        if(art2.appendToBottom(art1) == true){
            //Appending a normal object to an empty object
        
            if (art1.appendToBottom(art1) == true){
                //appending an object to itself
                return result;
        
            }
        }
    }
    else{
        
        result = false;
    }
    return result;

}


bool Tester::TestAppendToBottomError(){
    //Testing append to bottom function for error case(Does not have same width)    
    bool result = true;
    Art art1(4,7);
    Art art2(2,4);   
    if (art2.appendToBottom(art1) == true){
        return result;
    }
    else{
        result = false;
    }
    return result;
}



bool Tester::TestAppendToBottomNormal(){
    //Testing normal case
    bool result = true;
    Art art1(4,9);
    Art art2(2,9);
    if (art2.appendToBottom(art1) == true){
        return result;
    }
    else{
        result = false;
    }
    return result;
}

bool Tester::TestAppendToRight(){
    //Testing append to right function with normal objects, empty objects, and to self

    bool result = true;
    Art art1(13,5);
    Art art2(0,0);
    if(art1.appendToRight(art2) == true){
        //Appending an empty object to a normal object
        
        if(art2.appendToRight(art1) == true){
            //Appending a normal object to an empty object
            
        
            if (art1.appendToRight(art1) == true){
                //appending an object to itself
                
                return result;
        
            }
        }
    }
    else{
        result = false;
    }
    return result;

}


bool Tester::TestAppendToRightError(Art &art){
    //Testing Append to right with an error case (invalid height)
    bool result = true;
    Art art15(7,4);
    if (art15.appendToRight(art) == true){
        return result;
    }
    else{
        result = false;
        return result;
    }
    
}

bool Tester::TestAppendToRightNormal(Art &art){
    //Test append to right function for normal case(same height)
    bool result = true;
    Art art13(7,4);
    if (art13.appendToRight(art) == true){
        return result;
    }
    else{
        result = false;
        return result;
    }
    
}


bool Tester::testOperatorEdge(Art &art){
    //Copies an empty object correctly
    bool result = true;
    Art art11(9,9);
    art11 = art;
    //check if the rows and columns were successfully copied over
    if ((art11.m_numRows== art.m_numRows)&&(art.m_numColumns== art11.m_numColumns)){
        result = true;
        //checks memory locations
            if (&art11.m_masterPiece != &art.m_masterPiece){
                result = true;
            }
            else{
                result = false;
            }
        
    }
    return result;
    
}

bool Tester::testOperatorNormal( Art & art){
    //checking if assignemnt operator successfully copies object and stores in different
    //memory block in a normal case
    bool result = true;
    Art art9(9,9);
    art9 = art;
    
    for(int i =0; i < art9.m_numRows; i++){
        for (int j =0; j < art9.m_numColumns; j++){
            //check to see if the same color code values
            if (art9.m_masterPiece[i][j] == art.m_masterPiece[i][j]){
                result = true;
            }
            else{
                result = false;
            }
        }
    }
    //check memory block locations
    if (&art9.m_masterPiece != &art.m_masterPiece){
        result = true;
        return result;
    }
    else{
        result = false;
        return result;
    }

}

bool Tester::testCopyConstructorEdge(){
    //copy an empty object with different memory blocks
    bool result = true;
    Art art7(0,0);
    art7.create(10);
    Art art8(art7);
    //checking for rows and memory locations
    if ((&art7.m_masterPiece != &art8.m_masterPiece)&&
    ( art7.m_numColumns == art8.m_numColumns)&&(art7.m_numRows == art8.m_numRows)){
        
        return result;
    }
    else{
        result = false;
        
    }
    return result;
}

bool Tester::testCopyConstructorNormal(){
    //testing the functionality of the copy constructor
    //all color codes must match current and new objects, and be different memory blocks
    bool result = true;
    Art art5(5,5);
    art5.create(10);
    Art art6(art5);

    if ((&art5.m_masterPiece != &art6.m_masterPiece)&&
    ( art5.m_numColumns == art6.m_numColumns)&&(art5.m_numRows == art6.m_numRows)){
        for (int i = 0; i < art6.m_numRows; i++){
            for (int j = 0; j < art6.m_numColumns; j ++){
                //check if the color codes values are the same
                if (art6.m_masterPiece[i][j] == art5.m_masterPiece[i][j]){
                    result = true;
                    
                }
                else{
                    return false;
                }
            }
        }
    }
    else{
        result = false;
    }
    return result;
}

bool Tester::testCreateNormal(Art & art){
    // this function assumes the art object is not empty
    // all color codes must be within the correct range
    bool result = true;
    art.create(10);
    if (art.m_numRows > 0 && art.m_numColumns > 0 && art.m_masterPiece != nullptr){
        for (int i=0; i < art.m_numRows; i++){
            for (int j=0; j < art.m_numColumns; j++){
                if(art.m_masterPiece[i][j] < 30 ||
                    art.m_masterPiece[i][j] > 37){
                        result = false;
                        return result;
                    }
                    
            }   
        }
    }
    else{
        result = false;
        
    }
    return result;
}

bool Tester::testCreateError(Art & art){
    //Checking to see if object is turned to an empty one
    art.create(10);
    bool result = true;
    //check if rows and columns are zero and is pointing to nullptr
    if(((art.m_numRows == 0) && (art.m_numColumns == 0)&&(art.m_masterPiece == nullptr))){
        
        return result;
    }
    else{
        result = false;
        
        return result;
    }
}

bool Tester::testCreateEdge(Art & art){
    //Passing in an error case
    art.create(10);
    bool result = true;
    //checking if a 1x1 is made
    if(((art.m_numRows == 1) && (art.m_numColumns == 1)&&(art.m_masterPiece != nullptr))){
        for (int i=0; i < art.m_numRows; i++){
            for (int j=0; j < art.m_numColumns; j++){
                //checking if value is in between min and max
                if(art.m_masterPiece[i][j] < 30 ||
                    art.m_masterPiece[i][j] > 37){
                        result = false;
                    }
                    
            }   
        }
        
    }
    else{
        result = false;
    }
    
    return result;
}


void Tester::measureInsertionTime(int numTrials, int inputSize)
{
    //Measuring the efficiency of insertion algorithm with system clock ticks
    //Clock ticks are units of time of a constant but system-specific length, as those returned by function clock().
    //Dividing a count of clock ticks by CLOCKS_PER_SEC yields the number of seconds.
    const int a = 2;//scaling factor for input size
    double T = 0.0;//to store running times
    clock_t start, stop;//stores the clock ticks while running the program
    for (int k=0;k<numTrials;k++)
    {
        Art testObject(inputSize,inputSize);
        start = clock();
        testObject.create(10);//the algorithm to be analyzed for efficiency
        stop = clock();
        T = stop - start;//number of clock ticks the algorithm took
        cout << "\tInserting " << inputSize * inputSize << " members took " << T << " clock ticks ("<< T/CLOCKS_PER_SEC << " seconds)!" << endl;
        inputSize = inputSize * a;//increase the input size by the scaling factor
    }
}
