package cn.hrbust.dao;

import cn.hrbust.pojo.User;
import junit.framework.TestCase;
import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.query.NativeQuery;
import org.hibernate.query.Query;

import java.lang.module.Configuration;
import java.sql.Date;
import java.util.List;

public class QueryByNativeSQL extends TestCase {

  //1.通过NativeQuery查询年龄大于40的用户
  //基本SQL查询
  public void testQueryUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try{
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();

      NativeQuery nq = session.createNativeQuery("select * from T_USER u where u.age > 40", User.class);
      //nq.addEntity(User.class);
      List users = nq.getResultList();
      for(int i = 0 ; i < users.size() ; i++){
        User u = (User) users.get(i);
        System.out.println(u.toString());
      }
      ts.commit();
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //session.close();
      //sf.close();
    }
  }

  //2.基本的SQL查询，通过标签查询
  public void testQueryByTag(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try{
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      Query nq = session.getNamedQuery("findUsersByName");
      List users = nq.getResultList();
      for(int i = 0 ; i < users.size() ; i++){
        User u = (User) users.get(i);
        System.out.println(u.toString());
      }
      ts.commit();
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //session.close();
      //sf.close();
    }
  }

  //3.基本的SQL查询，保存瞬时用户对象
  public void testSaveUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    User u = new User();
    u.setName("zouchaolin");
    u.setGender("男");
    u.setAge(21);
    u.setBirthday(Date.valueOf("1999-12-1"));
    //u: 瞬时对象，没有对象id，没有纳入Session管理，他的任何变化不会自动地发送SQL语句
    u.setName("zouchaolin");
    try {
      sf = HibernateUtil.getSf(); //sessionfactory单态模式
      session = sf.getCurrentSession();  //保证每个读写线程有唯一的session实例
      ts = session.beginTransaction();
      session.save(u);
      //u:  持久对象，有对象id，纳入Session管理，他的任何变化会自动地发送SQL语句
      //u.setName("zuochaolin");  //属性改变，持久化对象的属性变化会发送update语句
      ts.commit();
      u.setName("zouchaolin");  //事务提交后，Session关闭，属性改变，此时的对象的属性变化不会发送update语句

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
