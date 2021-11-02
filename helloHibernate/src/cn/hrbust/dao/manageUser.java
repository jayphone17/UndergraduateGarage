package cn.hrbust.dao;

import cn.hrbust.pojo.User;
import junit.framework.TestCase;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.Query;
import org.hibernate.sql.Update;
import org.junit.Test;
import java.lang.module.Configuration;
import java.sql.Date;
import java.util.List;


public class manageUser extends TestCase {
  //保存用户
  public void testSavaUser(){
    User user = new User();
    user.setName("保存对象");
    user.setGender("male");
    user.setAge(22);
    user.setBirthday(Date.valueOf("1998-05-11"));
    //这里的user对象是瞬时对象，没有对象id，没有纳入session管理
    //他的任何变化不会自动发送SQL语句
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      //sessionFactory单例模式
      session = sf.getCurrentSession();
      //保证每个读写线程有一个唯一的session
      ts = session.beginTransaction();
      session.save(user);
      //这里的user是持久对象，有对象id，纳入session管理
      ts.commit();
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //getCurrentSession会自动关闭session，可以不加close()
      session.close();
      sf.close();
    }
  }

  //查询用户对象
  public void testQueryUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;

    try {
      sf = HibernateUtil.getSf();
      //sessionFactory单例模式
      session = sf.getCurrentSession();
      //保证每个读写线程有一个唯一的session
      ts = session.beginTransaction();

      Query query = session.createQuery("from User");
      List<User> users = query.list();
      for (User u : users){
        System.out.println(u.getId()+" "+u.getName()+" "+u.getAge());
      }
      ts.commit();
      //如果在commit之后，事务提交，session关闭
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //getCurrentSession会自动关闭session，可以不加close()
      session.close();
      sf.close();
    }
  }

  //查询一个对象
  public void testGetUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      //sessionFactory单例模式
      session = sf.getCurrentSession();
      //保证每个读写线程有一个唯一的session
      ts = session.beginTransaction();
      User user = session.get(User.class,5);
      //得到的是持久化对象，已经纳入Session管理
      System.out.println(user.getName()+" "+user.getAge());
      user.setName("linjiefeng");
      user.setAge(111);
      //验证是否是持久化对象，如果是，会同步到数据库
      ts.commit();
      //如果在commit之后，事务提交，session关闭
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //getCurrentSession会自动关闭session，可以不加close()
      session.close();
      sf.close();
    }
  }

  //删除一个对象
  public void testDeleteUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      //sessionFactory单例模式
      session = sf.getCurrentSession();
      //保证每个读写线程有一个唯一的session
      ts = session.beginTransaction();
      User user = session.get(User.class,3);
      //得到的是持久化对象，已经纳入Session管理
      session.delete(user);
      //删除之后是瞬时对象，准确来说是删除对象
      ts.commit();
      //如果在commit之后，事务提交，session关闭
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //getCurrentSession会自动关闭session，可以不加close()
      session.close();
      sf.close();
    }
  }

  //更新一个对象
  public void testUpdateUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      //sessionFactory单例模式
      session = sf.getCurrentSession();
      //保证每个读写线程有一个唯一的session
      ts = session.beginTransaction();
      User user = session.get(User.class,4);
      //得到的是持久化对象，已经纳入Session管理
      user.setName("xiaoli");
      user.setAge(999);
      session.update(user);
      //更新后得到持久化对象，纳入Session管理
      ts.commit();
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //getCurrentSession会自动关闭session，可以不加close()
      session.close();
      sf.close();
    }
  }
  //托管对象
  public void testDetachedUser(){
    User user = new User();
    user.setName("jayphone");
    user.setGender("male");
    user.setAge(22);
    user.setBirthday(Date.valueOf("1998-05-11"));
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      //sessionFactory单例模式
      session = sf.getCurrentSession();
      //保证每个读写线程有一个唯一的session
      ts = session.beginTransaction();
      session.saveOrUpdate(user);
      ts.commit();
      //如果在commit之后，事务提交，session关闭
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //getCurrentSession会自动关闭session，可以不加close()
      //session.close();
      //sf.close();
    }
    //user此时为托管对象，有对象id，没有Session管理，不会自动发SQL
    //但数据数据库有对应记录
    //怎么重新变为持久化对象？
    user.setName("linjiefeng");
    user.setAge(22);
    try {
      sf = HibernateUtil.getSf();
      //sessionFactory单例模式
      session = sf.getCurrentSession();
      //保证每个读写线程有一个唯一的session
      ts = session.beginTransaction();
      session.saveOrUpdate(user);
      ts.commit();
      //如果在commit之后，事务提交，session关闭
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //getCurrentSession会自动关闭session，可以不加close()
      //session.close();
      //sf.close();
    }
  }

  //更新托管对象
  public void testUpdateDetachedUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    User user = new User();

    try {
      sf = HibernateUtil.getSf();
      //sessionFactory单例模式
      session = sf.getCurrentSession();
      //保证每个读写线程有一个唯一的session
      ts = session.beginTransaction();
      session.get(User.class,4);
      ts.commit();
      //如果在commit之后，事务提交，session关闭
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //getCurrentSession会自动关闭session，可以不加close()
      //session.close();
      //sf.close();
    }
    user.setName("linlin");
    try {
      sf = HibernateUtil.getSf();
      //sessionFactory单例模式
      session = sf.getCurrentSession();
      //保证每个读写线程有一个唯一的session
      ts = session.beginTransaction();
      session.update(user);
      //由于配置了select-update-before-update属性
      //所有hibernate会先发一条sql语句
      //会查看对象状态是否真的变化
      //再决定是否更新
      ts.commit();
      //如果在commit之后，事务提交，session关闭
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //getCurrentSession会自动关闭session，可以不加close()
      //session.close();
      //sf.close();
    }
  }

  //清除一个对象
  @Test
  public void testEvictUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      //sessionFactory单例模式
      session = sf.getCurrentSession();
      //保证每个读写线程有一个唯一的session
      ts = session.beginTransaction();
      User user = session.get(User.class,2);
      //得到的是持久化对象，已经纳入Session管理
      session.evict(user);
      //把对象脱离当前Session的管理
      ts.commit();
      //如果在commit之后，事务提交，session关闭
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //getCurrentSession会自动关闭session，可以不加close()
      session.close();
      sf.close();
    }
  }

  //get和load的区别
  public void testGetAndLoadUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      //sessionFactory单例模式
      session = sf.getCurrentSession();
      //保证每个读写线程有一个唯一的session
      ts = session.beginTransaction();
      //Get方法
      User user = session.get(User.class,2);
      if(user!=null){
        System.out.println(user.getName()+" "+user.getAge());
      }
      //Load方法
      User user1 = session.load(User.class,4);
      System.out.println("load方法加载对象");
      System.out.println(user1.getName()+" "+user1.getAge());
      //load返回的是一个代理对象

      ts.commit();
      //如果在commit之后，事务提交，session关闭
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //getCurrentSession会自动关闭session，可以不加close()
      session.close();
      sf.close();
    }
  }

  //用load方法查询一个对象
  public void testLoadUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      //sessionFactory单例模式
      session = sf.getCurrentSession();
      //保证每个读写线程有一个唯一的session
      ts = session.beginTransaction();
      //Load方法
      User user1 = session.load(User.class,4);
      System.out.println("load方法加载对象");
      System.out.println(user1.getName()+" "+user1.getAge());
      //load返回的是一个代理对象
      ts.commit();
      //如果在commit之后，事务提交，session关闭
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //getCurrentSession会自动关闭session，可以不加close()
      session.close();
      sf.close();
    }
  }

  public void testUpdateObjectWithDynamicUpdate(){

  }

  //对象识别
  public void testObjectIdentify(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      //sessionFactory单例模式
      session = sf.getCurrentSession();
      //保证每个读写线程有一个唯一的session
      ts = session.beginTransaction();

      String a = "abc";
      String b = "abc";
      System.out.println(a==b);
      System.out.println(a.equals(b));

      String c = "mnp";
      String d = new String("mnp");
      System.out.println(c==d);
      System.out.println(c.equals(d));

      ts.commit();
      //如果在commit之后，事务提交，session关闭
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //getCurrentSession会自动关闭session，可以不加close()
      session.close();
      sf.close();
    }
  }

  //User对象识别
  public void testUserObjectIdentify(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    User u1 = null;
    User u2 = null;
    try {
      sf = HibernateUtil.getSf();
      //sessionFactory单例模式
      session = sf.getCurrentSession();
      //保证每个读写线程有一个唯一的session
      ts = session.beginTransaction();

      u1 = session.get(User.class,2);
      u2 = session.get(User.class,2);
      System.out.println(u1==u2);//同一个session，引用相同

      ts.commit();
      //如果在commit之后，事务提交，session关闭
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //getCurrentSession会自动关闭session，可以不加close()
      session.close();
      sf.close();
    }
    System.out.println(u1==u2);
    System.out.println(u1.equals(u2));
  }

  public static void main (String[] args){

    User user = new User();
    user.setName("zhuhanshu");
    user.setGender("male");
    user.setAge(22);
    user.setBirthday(Date.valueOf("1998-05-11"));

    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;

    try {
      sf = HibernateUtil.getSf();
      //sessionFactory单例模式
      session = sf.getCurrentSession();
      //保证每个读写线程有一个唯一的session
      ts = session.beginTransaction();
      session.save(user);
      ts.commit();
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }finally {
      //getCurrentSession会自动关闭session，可以不加close()
      session.close();
      sf.close();
    }
  }
}
