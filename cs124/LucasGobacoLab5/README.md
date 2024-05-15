

Makefile is provided.

make clean - remove ./main and *.o
make

The main binary is generated as "main"

The main() function loads the types of data into four classes.

faculty-data.csv loads into a collection of FACULTY objects.

section-data.csv loads into a collection of SECTION objects.

grade-scale-data.csv loads into a collection of GRADE_SCALE objects

assignment-data.csv loads into a collection of ASSIGNMENT objects.

1. FACULTY class
    a. Attributes
        FacultyId
        FirstName
        LastName
        Department
        Address
        City
        State
        Zip
        Email
        Phone
        List of Sections
    b. Sample Data:
        1. faculty-data.csv

2.  SECTION class
     a. Attributes
        SectionId
        Term
        Course Name
        Faculty (object)
        List of GradeScales
    b. Sample Data:
        1. section-data.csv

3.  GRADE_SCALE class
    a. Attributes
        GradeScaleId
        Section (object)
        Description
        Weight
        List of Assignments
    b. Sample Data:
        1. grade-scale-data.csv

4. ASSIGNMENT class
    a. Attributes:
        AssignmentId
        GradeScale (object)
        Description
        StartDate
        EndDate
        PossiblePoints
        Points
    b. Sample Data:
        1. assignment-data.csv


RELATIONSHIPS:

FACULTY - SECTION
1 - MANY

SECTION - GRADE_SCALE
1 - MANY

GRADE-SCALE TO ASSIGNMENT
1 - MANY

