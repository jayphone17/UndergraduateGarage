package cn.tf.department.dao;

import java.util.List;

import cn.tf.base.BaseDao;
import cn.tf.classes.domain.CrmClass;
import cn.tf.department.domain.CrmDepartment;
import cn.tf.lessontype.domain.CrmLessontype;

public interface  DepartmentDao extends  BaseDao<CrmDepartment>{
  //增
  void save (CrmDepartment crmDepartment);
  //删
  void delete(CrmDepartment crmDepartment);
  //改
  void update(CrmDepartment crmDepartment);
  //查
  List<CrmDepartment> findAllDepartment();

}
