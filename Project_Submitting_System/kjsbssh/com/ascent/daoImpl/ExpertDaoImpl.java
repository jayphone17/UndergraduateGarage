//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.daoImpl;

import com.ascent.dao.ExpertDao;
import com.ascent.pojo.Expert;
import java.sql.SQLException;
import java.util.List;
import org.hibernate.Hibernate;
import org.hibernate.HibernateException;
import org.hibernate.Query;
import org.hibernate.Session;
import org.springframework.orm.hibernate3.HibernateCallback;
import org.springframework.orm.hibernate3.support.HibernateDaoSupport;

public class ExpertDaoImpl extends HibernateDaoSupport implements ExpertDao {
  public ExpertDaoImpl() {
  }

  public void addExpert(Expert expert) {
    this.getHibernateTemplate().save(expert);
  }

  public void deleteExpert(Expert expert) {
    this.getHibernateTemplate().delete(expert);
  }

  public List<Expert> findAllExpert(final int pagno, final int maxrows) {
    return (List)this.getHibernateTemplate().execute(new HibernateCallback() {
      public Object doInHibernate(Session session) throws HibernateException {
        Query query = session.createQuery("from Expert e order by e.expertid");
        query.setFirstResult((pagno - 1) * maxrows);
        query.setMaxResults(maxrows);
        List<Expert> experts = query.list();
        return experts;
      }
    });
  }

  public Expert findExpertById(Integer id) {
    Expert expert = (Expert)this.getHibernateTemplate().load(Expert.class, id);
    expert.getUser().getPassword();
    Hibernate.initialize(expert.getProjectCategories());
    Hibernate.initialize(expert.getName());
    return expert;
  }

  public int getTotalCount() {
    List list = this.getHibernateTemplate().find("select count(e.expertid) from Expert e");
    return (Integer)list.get(0);
  }

  public void updateExpert(Expert expert) {
    this.getHibernateTemplate().update(expert);
  }
}
