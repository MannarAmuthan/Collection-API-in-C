#ifndef STUDENT_CLASS
#define STUDENT_CLASS

struct Student{
	int roll;
	char name[10];
};

//This will be used as comparator
int compare(void* one,void* two){
	struct Student *op1,*op2;
	op1=(struct Student*) one;
	op2=(struct Student*) two;

    if(op1->roll==op2->roll){
      return 0;
    }

    if(op1->roll>op2->roll){
      return 1;
    }

    if(op1->roll<op2->roll){
      return -1;
    }
    return -1;
}


#endif