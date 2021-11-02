package cn.tf.classes.dao.impl;

import cn.tf.base.BaseDao;
import cn.tf.base.impl.BaseDaoImpl;
import cn.tf.classes.dao.ClassesDao;
import cn.tf.classes.domain.CrmClass;
import cn.tf.department.domain.CrmDepartment;

import java.util.List;

public class ClassesDaoImpl extends   BaseDaoImpl<CrmClass>  implements ClassesDao{
  //增
  public void save(CrmDepartment crmDepartment){
    this.getHibernateTemplate().save(crmDepartment);
  }
  //删
  public void delete(CrmDepartment crmDepartment){
    this.getHibernateTemplate().delete(crmDepartment);
  }
  //改
  public void update(CrmDepartment crmDepartment){
    String hql4="update CrmClass c set c.name=? c.beginTime=? c.endTime=? c.state=? c.totalCount=? c.goCount=? where c.classID=?";
    this.getHibernateTemplate().bulkUpdate(hql4);
  }
  //查
  public List<CrmClass> findAllClass() {
    return this.getHibernateTemplate().find("from CrmClass");
  }
}
