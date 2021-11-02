//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.daoImpl;

import com.ascent.dao.UserDao;
import com.ascent.pojo.User;
import com.ascent.pojo.Usergroup;
import java.sql.SQLException;
import java.util.Iterator;
import java.util.List;
import org.hibernate.Hibernate;
import org.hibernate.HibernateException;
import org.hibernate.Query;
import org.hibernate.Session;
import org.springframework.orm.hibernate3.HibernateCallback;
import org.springframework.orm.hibernate3.support.HibernateDaoSupport;

public class UserDaoImpl extends HibernateDaoSupport implements UserDao {
  public UserDaoImpl() {
  }

  public void addUser(User user) {
    this.getHibernateTemplate().save(user);
  }

  public void deleteUser(User user) {
    this.getHibernateTemplate().delete(user);
  }

  public List<User> findAllUser(final int pageno, final int maxrows) {
    return (List)this.getHibernateTemplate().execute(new HibernateCallback() {
      public Object doInHibernate(Session session) throws HibernateException {
        Query query = session.createQuery("from User u order by u.uid desc");
        query.setFirstResult((pageno - 1) * maxrows);
        query.setMaxResults(maxrows);
        List<User> list = query.list();
        Iterator var5 = list.iterator();

        while(var5.hasNext()) {
          User u = (User)var5.next();
          u.getUsergroup().getGname();
        }

        return list;
      }
    });
  }

  public User findUserById(Integer id) {
    User user = (User)this.getHibernateTemplate().load(User.class, id);
    Hibernate.initialize(user.getUsergroup());
    return user;
  }

  public void updateUser(User user) {
    this.getHibernateTemplate().update(user);
  }

  public User loginCheck(User user) {
    List<User> u = this.getHibernateTemplate().findByExample(user);
    return (User)u.get(0);
  }

  public int getTotalCount() {
    List users = this.getHibernateTemplate().find("select count(u.uid) from User u");
    return (Integer)users.get(0);
  }

  public Usergroup findUserGroupById(int id) {
    Usergroup group = (Usergroup)this.getHibernateTemplate().load(Usergroup.class, id);
    return group;
  }

  public List<User> findAllExpertByGroup(Integer id) {
    List<User> users = (List<User>) this.getHibernateTemplate().find("from User u where uid=2");
    return users;
  }

  public List<User> findAllUnitByGroup(Integer id) {
    List<User> units = (List<User>) this.getHibernateTemplate().find("from User u where uid=3");
    return units;
  }
}
