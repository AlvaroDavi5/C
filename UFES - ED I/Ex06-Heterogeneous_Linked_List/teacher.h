#ifndef _TEACHER_H

	#define _TEACHER_H

	typedef struct teacher Teacher;

	Teacher * initTeacher(int regist, char *name, float wage);
	void printTeacher(Teacher *teacher);
	int returnRegisterTeacher(Teacher *teacher);
	char * returnNameTeacher(Teacher *teacher);
	float returnWageTeacher(Teacher *teacher);
	void destroyTeacher(Teacher *teacher);

#endif

