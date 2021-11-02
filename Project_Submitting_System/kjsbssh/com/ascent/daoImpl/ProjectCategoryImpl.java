//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.daoImpl;

import com.ascent.dao.ProjectCategoryDao;
import com.ascent.pojo.ProjectCategory;
import java.sql.SQLException;
import java.util.Iterator;
import java.util.List;
import org.hibernate.Hibernate;
import org.hibernate.HibernateException;
import org.hibernate.Query;
import org.hibernate.Session;
import org.springframework.orm.hibernate3.HibernateCallback;
import org.springframework.orm.hibernate3.support.HibernateDaoSupport;

public class ProjectCategoryImpl extends HibernateDaoSupport implements ProjectCategoryDao {
  public ProjectCategoryImpl() {
  }

  public void addProjectCategory(ProjectCategory category) {
    this.getHibernateTemplate().save(category);
  }

  public void deleteProjectCategory(ProjectCategory category) {
    this.getHibernateTemplate().delete(category);
  }

  public List<ProjectCategory> findAllProjectCategoryByPage(final int pageno, final int maxrows) {
    return (List)this.getHibernateTemplate().execute(new HibernateCallback() {
      public Object doInHibernate(Session session) throws HibernateException {
        Query query = session.createQuery("from ProjectCategory pc order by pc.categoryid desc");
        query.setFirstResult((pageno - 1) * maxrows);
        query.setMaxResults(maxrows);
        List<ProjectCategory> categorys = query.list();
        Iterator var5 = categorys.iterator();

        while(var5.hasNext()) {
          ProjectCategory cgs = (ProjectCategory)var5.next();
          cgs.getExpert().getName();
        }
        return categorys;
      }
    });
  }

  public ProjectCategory findProjectCategoryById(Integer id) {
    ProjectCategory category = (ProjectCategory)this.getHibernateTemplate().load(ProjectCategory.class, id);
    Hibernate.initialize(category.getCategoryname());
    category.getProjects();
    return category;
  }

  public int getTotalCount() {
    List list = this.getHibernateTemplate().find("select count(c.categoryid) from ProjectCategory c");
    Hibernate.initialize(list.get(0));
    return (Integer)list.get(0);
  }

  public void updateProjectCategory(ProjectCategory category) {
    this.getHibernateTemplate().update(category);
  }
}
