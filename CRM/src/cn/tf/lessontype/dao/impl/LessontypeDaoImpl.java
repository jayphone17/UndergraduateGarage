package cn.tf.lessontype.dao.impl;
import cn.tf.base.impl.BaseDaoImpl;
import cn.tf.department.domain.CrmDepartment;
import cn.tf.lessontype.dao.LessontypeDao;
import cn.tf.lessontype.domain.CrmLessontype;
import java.io.Serializable;
import java.util.List;

public class LessontypeDaoImpl extends  BaseDaoImpl<CrmLessontype>  implements LessontypeDao{
  //增
  public void save(CrmLessontype crmLessontype){
    this.getHibernateTemplate().save(crmLessontype);
  }
  //删
  public void delete(CrmLessontype crmLessontype){
    this.getHibernateTemplate().delete(crmLessontype);
  }
  //改
  public void update(CrmLessontype crmLessontype){
    String hql3="update CrmLessontype l set l.lessonCost=? l.total=? l.lessonName=? l.remark=? where l.lessonTypeID=?";
    this.getHibernateTemplate().bulkUpdate(hql3);
  }
  //查
  public List<CrmLessontype> findAll(String lessonTypeID) {
    return this.getHibernateTemplate().find("from CrmDepartment");
  }

  public List<CrmLessontype> findAll() {
    return this.getHibernateTemplate().find("from CrmDepartment");
  }
}
