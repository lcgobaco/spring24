1. FACULTY class
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

2.  SECTION class
SectionId
Term
Course Name
Faculty (object)
List of Groups

3.  GROUP class
GroupId
Section (object)
Description
Weight
List of Assignments

4. ASSIGNMENT class
AssignmentId
Group (object)
Description
StartDate
EndDate
PossiblePoints
Points


