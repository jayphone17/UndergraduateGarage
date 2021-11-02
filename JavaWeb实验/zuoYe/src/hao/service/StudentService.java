package hao.service;

import java.util.List;

import org.apache.poi.hssf.usermodel.HSSFWorkbook;

import hao.vo.Student;

public interface StudentService {
	List<Student> findAllStudent();
	String FindResumePath(String stuId);
	HSSFWorkbook getWorkbook(String min, String max);
	boolean upload(Student student);
	boolean update(Student student,int stuId);
	boolean delete(Student student);
	Student login(String stuId, String password);
}
