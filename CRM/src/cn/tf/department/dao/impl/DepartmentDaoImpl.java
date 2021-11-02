package cn.tf.department.dao.impl;
import java.util.List;
import org.springframework.orm.hibernate3.support.HibernateDaoSupport;
import cn.tf.base.impl.BaseDaoImpl;
import cn.tf.classes.dao.ClassesDao;
import cn.tf.classes.domain.CrmClass;
import cn.tf.department.dao.DepartmentDao;
import cn.tf.department.domain.CrmDepartment;

public class DepartmentDaoImpl extends BaseDaoImpl<CrmDepartment> implements DepartmentDao{
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
    String hql3="update CrmDepartment d set d.depName=? where d.depID=?";
    this.getHibernateTemplate().bulkUpdate(hql3);
  }
  //查
	public List<CrmDepartment> findAllDepartment() {
		return this.getHibernateTemplate().find("from CrmDepartment");
	}
}
