package hao.service;

import java.io.FileReader;
import java.io.InputStream;
import java.util.List;
import java.util.Properties;

import org.apache.poi.hssf.usermodel.HSSFRow;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;

import hao.dao.StudentDao;
import hao.dao.StudentDaoImpl;

import hao.vo.CollegeMap;
import hao.vo.Student;

public class StudentServiceImpl implements StudentService {
	
	private StudentDao stuDao = new StudentDaoImpl();
	private static String UPLOADROOT = null;
	
	static{
		try {
    		Properties properties = new Properties();
    		properties.load(new FileReader("D:/eclipse-oxygen-workspace/zuoYe/src/hao/config/dbConfig.properties"));
    		String filepath = StudentServiceImpl.class.getResource("/").getPath();
			System.out.println("LookingforPath:"+filepath);
			
			//System.out.println(System.getProperty("user.dir"));
			UPLOADROOT = properties.getProperty("uploadroot").trim();
			
			//properties.load(new FileReader("F:/eclipse-jee_workspace/zuoYe/src/hao/config/dbConfig.properties"));
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}
	
	@Override
	public List<Student> findAllStudent() {
		
		return stuDao.findAllStu();
	}
	
	@Override
	public String FindResumePath(String stuId) {
		int id = Integer.valueOf(stuId);
		String path = stuDao.findResumeById(id);
		return path;
	}
	
	@Override
	public HSSFWorkbook getWorkbook(String mi, String ma) {
		int min = Integer.valueOf(mi);
		int max = Integer.valueOf(ma);
		List<Student> stuList = stuDao.findStuByAge(min, max);
		if (stuList.isEmpty()) {
			return null;
		} else {
			// 声明一个工作薄
			HSSFWorkbook workbook = new HSSFWorkbook();
			// 生成一个表格
			HSSFSheet sheet = workbook.createSheet("Student");
			// 设置表格默认列宽度为15个字节
			sheet.setDefaultColumnWidth((short) 15);
			
			HSSFRow row = sheet.createRow(0);
			row.createCell(0).setCellValue("学号");
			row.createCell(1).setCellValue("姓名");
			row.createCell(2).setCellValue("性别");
			row.createCell(3).setCellValue("年龄");
			row.createCell(4).setCellValue("身高");
			row.createCell(5).setCellValue("学院");
			int i = 1;			 
			for (Student stu : stuList) {
				row = sheet.createRow(i++);
				row.createCell(0).setCellValue(stu.getStuId());
				row.createCell(1).setCellValue(stu.getName());
				row.createCell(2).setCellValue(stu.getSex());
				row.createCell(3).setCellValue(stu.getAge());
				row.createCell(4).setCellValue(stu.getHeight());
				row.createCell(5).setCellValue(stu.getCollege());
			}
			return workbook;
		}
	}
	
	@Override
	public boolean upload(Student student){
		String collegeName = CollegeMap.getCollegeName(student.getCollege());
		student.setCollege(collegeName);
		
		if(student.getSex().equals("male")){
			student.setSex("男");
		}else{
			student.setSex("女");
		}
		if(!student.getPhoto().equals("")){
			student.setPhoto(UPLOADROOT+student.getPhoto());
		}
		if(!student.getResume().equals("")){
			student.setResume(UPLOADROOT+student.getResume());
		}
		return stuDao.upload(student);
	}
	
	@Override
	public Student login(String stuId, String password) {
		int id = Integer.valueOf(stuId);
		Student stu = stuDao.login(id, password);
		if(stu!=null){
			stu.setCollege(CollegeMap.getCollegeKey(stu.getCollege()));
		}
		return stu;
	}

	@Override
	public boolean delete(Student student) {
		int stuId = student.getStuId();
		return stuDao.delete(stuId);
	}

	@Override
	public boolean update(Student student, int stuId) {
		String collegeName = CollegeMap.getCollegeName(student.getCollege());
		student.setCollege(collegeName);
		if(stuDao.findStuById(stuId)!=null){
			return stuDao.update(student, stuId);
		}
		return false;
	}
}
