package hao.dao;

import java.util.List;

import hao.vo.Student;

public interface StudentDao {
	boolean upload(Student student);
	boolean update(Student student,int stuId);
	boolean delete(int stuId);
	Student findStuById(int stuId);
	String findResumeById(int stuId);
	List<Student> findStuByAge(int min, int max);
	List<Student> findAllStu();
	Student login(int stuId,String password);
}
