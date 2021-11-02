package hao.vo;

import java.util.HashMap;
import java.util.Map;

public class CollegeMap {
	private static Map<String,String> map;
	
	static{
		map = new HashMap<String,String>();
		map.put("A", "软件学院");
		map.put("B", "自动化学院");
		map.put("C", "法学院");
		map.put("D", "外国语学院");
		map.put("E", "电气与电子工程学院");
		map.put("F", "计算机科学与技术学院");
		map.put("G", "应用科学学院");
		map.put("软件学院", "A");
		map.put("自动化学院", "B");
		map.put("法学院", "C");
		map.put("外国语学院", "D");
		map.put("电气与电子工程学院", "E");
		map.put("计算机科学与技术学院", "F");
		map.put("应用科学学院", "G");
	}
	
	public static String getCollegeName(String key){
		return map.get(key);
	}
	
	public static String getCollegeKey(String value){
		return map.get(value);
	}
}
