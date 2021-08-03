#ifndef _STUDENT_H

	#define _STUDENT_H

	typedef struct student Student;

	Student * initStudent(int regist, char *name, float note);
	void printStudent(Student *student);
	int returnRegisterStudent(Student *student);
	char * returnNameStudent(Student *student);
	float returnNoteStudent(Student *student);
	void destroyStudent(Student *student);

#endif

