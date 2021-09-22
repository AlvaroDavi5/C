#ifndef STUDENT_H
	#define STUDENT_H

	typedef struct student Student;

	Student * createStudent(int regist, char *name, float note);
	void printStudent(Student *student);
	int returnRegisterStudent(Student *student);
	char * returnNameStudent(Student *student);
	float returnNoteStudent(Student *student);
	void freeStudent(Student *student);

#endif
