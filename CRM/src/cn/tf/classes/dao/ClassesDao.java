package cn.tf.classes.dao;

import cn.tf.base.BaseDao;
import cn.tf.classes.domain.CrmClass;
import cn.tf.department.domain.CrmDepartment;

import java.util.List;

public interface ClassesDao   extends  BaseDao<CrmClass>{
  //增
  void save (CrmClass  crmClass);
  //删
  void delete(CrmClass  crmClass);
  //改
  void update(CrmClass  crmClass);
  //查
  List<CrmClass> findAllClass();
}
