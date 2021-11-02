//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.daoImpl;

import com.ascent.dao.ProjectDao;
import com.ascent.pojo.Project;
import java.sql.SQLException;
import java.util.List;
import org.hibernate.HibernateException;
import org.hibernate.Query;
import org.hibernate.Session;
import org.springframework.orm.hibernate3.HibernateCallback;
import org.springframework.orm.hibernate3.support.HibernateDaoSupport;

public class ProjectDaoImpl extends HibernateDaoSupport implements ProjectDao {
  public ProjectDaoImpl() {
  }

  public void addProject(Project project) {
    this.getHibernateTemplate().save(project);
  }

  public void deleteProject(Project project) {
    this.getHibernateTemplate().delete(project);
  }

  public List<Project> findAllProject(final int pageno, final int maxrows) {
    return (List)this.getHibernateTemplate().execute(new HibernateCallback() {
      public Object doInHibernate(Session session) throws HibernateException {
        Query query = session.createQuery("from Project p order by p.projectId desc");
        query.setFirstResult((pageno - 1) * maxrows);
        query.setMaxResults(maxrows);
        List<Project> projects = query.list();
        return projects;
      }
    });
  }

  public Project findProjectById(Integer id) {
    Project project = (Project)this.getHibernateTemplate().load(Project.class, id);
    return project;
  }

  public int getTotalCount() {
    List list = this.getHibernateTemplate().find("select count(p.projectId) from Project p");
    return (Integer)list.get(0);
  }

  public void updateProject(Project project) {
    this.getHibernateTemplate().update(project);
  }
}
