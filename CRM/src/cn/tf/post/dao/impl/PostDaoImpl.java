package cn.tf.post.dao.impl;

import java.util.List;

import org.springframework.orm.hibernate3.support.HibernateDaoSupport;

import cn.tf.base.impl.BaseDaoImpl;
import cn.tf.department.dao.DepartmentDao;
import cn.tf.department.domain.CrmDepartment;
import cn.tf.post.dao.PostDao;
import cn.tf.post.domain.CrmPost;

public class PostDaoImpl extends BaseDaoImpl<CrmPost> implements PostDao{
  //增
  public void save(CrmPost crmPost){
    this.getHibernateTemplate().save(crmPost);
  }
  //删
  public void delete(CrmPost crmPost){
    this.getHibernateTemplate().delete(crmPost);
  }
  //改
  public void update(CrmPost crmPost){
    String hql2="update CrmPost p set p.name=? p.depID=?  where p.postID=?";
    this.getHibernateTemplate().bulkUpdate(hql2);
  }

  @Override
  public List<CrmPost> findAll(String departmentId) {
    return null;
  }

  //查
	public List<CrmPost> findAll() {
		return this.getHibernateTemplate().find("from CrmPost ");
	}
}
