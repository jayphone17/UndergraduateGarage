package cn.hrbust.dao;

import cn.hrbust.pojo.Group;
import cn.hrbust.pojo.User;
import junit.framework.TestCase;
import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

import java.lang.module.Configuration;
import java.sql.Date;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Association_Mapping_n_VS_n双向 extends TestCase {

  //基本查询
  public void testQueryUserAndGroup(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf(); //sessionfactory单态模式
      session = sf.getCurrentSession();  //保证每个读写线程有唯一的session实例
      ts = session.beginTransaction();
      Query query = session.createQuery("from Group g where g.name = '软件工程' ");
      List<Group> groups = query.getResultList();
      //默认是延迟加载加载相关用户
      for(Group g: groups){
        System.out.println(g.getName()+"包括的用户：");
        Set<User> users = g.getUsers();
        for(User u : users){
          System.out.println(u.getName());
        }
      }
      ts.commit();
    } catch (Exception e) {
      e.printStackTrace();
      if(ts != null){
        ts.rollback();
      }
    }finally{
      //session.close();
      //sf.close();
    }
  }

  //插入数据
  public void testSaveUserAndGroup(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    Group g1 = new Group();
    g1.setName("软件工程");
    Group g2 = new Group();
    g2.setName("计算机科学预计数");
    User u = new User();
    u.setName("linjiefeng");
    u.setGender("男");
    u.setAge(23);
    u.setBirthday(Date.valueOf("1998-05-11"));
    u.getGroups().add(g1);
    u.getGroups().add(g2);
    User u1 = new User();
    u1.setName("wangwei");
    u1.setGender("男");
    u1.setAge(22);
    u1.setBirthday(Date.valueOf("1999-12-1"));
    u1.getGroups().add(g1);
    Set users = new HashSet();
    users.add(u);
    users.add(u1);
    g1.setUsers(users);
    g2.getUsers().add(u);
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();  //保证每个读写线程有唯一的session实例
      ts = session.beginTransaction();
      session.save(g1);
      session.save(g2);
      ts.commit();
    } catch (HibernateException e) {
      e.printStackTrace();
      if(ts != null){
        ts.rollback();
      }
    }finally{
      //session.close();
      //sf.close();
    }
  }
}
