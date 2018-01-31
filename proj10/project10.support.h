
/********************************************************************/ 
/*  Declarations for Project #10                                    */
/********************************************************************/ 


struct student
{
  unsigned long number;      /* student's ID number (key)      */
  char name[25];             /* student's name                 */
  unsigned short exam1;      /* points on Exam #1              */
  unsigned short exam2;      /* points on Exam #2              */
  unsigned short hw;         /* points on homework             */
  unsigned short total;      /* total points (exams + hw)      */
  unsigned short percent;    /* percent of available (rounded) */
};


struct table
{

  unsigned short capacity;   /* number of elements in table    */
  unsigned short count;      /* number of students in table    */
  unsigned short available;  /* total points available         */
  struct student* memory;    /* pointer to array of students   */
};


/********************************************************************/
/*  Function:  search                                               */
/*                                                                  */
/*  Purpose:  locate and return a pointer to a student, if the      */
/*    student is present in the table.                              */
/*                                                                  */
/*  Arguments:                                                      */
/*    pointer to table of students                                  */
/*    identification number of student to be located                */
/*    pointer to pointer to student                                 */
/*                                                                  */
/*  Return value:                                                   */
/*    1 (true) if student located, 0 (false) otherwise              */
/********************************************************************/
 
int search( struct table*, unsigned long, struct student** );

 
/********************************************************************/
/*  Function:  delete                                               */
/*                                                                  */
/*  Purpose:  delete a student from the table, if the               */
/*    student is present in the table.                              */
/*                                                                  */
/*  Arguments:                                                      */
/*    pointer to table of students                                  */
/*    identification number of student to be deleted                */
/*                                                                  */
/*  Return value:                                                   */
/*    1 (true) if student deleted, 0 (false) otherwise              */
/********************************************************************/
 
int delete( struct table*, unsigned long );

/********************************************************************/
/*  Function:  insert                                               */
/*                                                                  */
/*  Purpose:  insert a student into the table, as long              */
/*    as there is room in the table and the student is not          */
/*    already present in the table.                                 */
/*                                                                  */
/*  Arguments:                                                      */
/*    pointer to table of students                                  */
/*    identification number of student to be inserted               */
/*    pointer to name of student                                    */
/*    points on Exam #1                                             */
/*    points on Exam #2                                             */
/*    points on homework                                            */
/*                                                                  */
/*  Return value:                                                   */
/*    1 (true) if student inserted, 0 (false) otherwise             */
/********************************************************************/

int insert( struct table*, unsigned long, char*, int, int, int );

