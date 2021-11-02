package cn.hrbust.dao;

import cn.hrbust.pojo.User;
import junit.framework.TestCase;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

import javax.persistence.criteria.CriteriaBuilder;
import javax.persistence.criteria.CriteriaQuery;
import javax.persistence.criteria.Predicate;
import javax.persistence.criteria.Root;
import java.lang.module.Configuration;
import java.util.List;

public class QueryByQBC extends TestCase {
  //1.基本的Criteria查询，查询所有属性
  public void testQueryUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();

      CriteriaQuery cq = session.getCriteriaBuilder().createQuery(User.class);
      cq.from(User.class);
      List users = session.createQuery(cq).getResultList();

      for(int i = 0 ; i < users.size() ; i++)
      {
        User u = (User)users.get(i);
        System.out.println(u.toString());
      }
      ts.commit();
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }
  }

  //2.条件查询1，查询名字带有linjiefeng的User
  public void testWhere1QueryUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();

      CriteriaBuilder cb = session.getCriteriaBuilder();
      CriteriaQuery<User> cq = cb.createQuery(User.class);
      Root<User> root = cq.from(User.class);
      //创建查询条件
      Predicate username = cb.equal(root.get("name"), "linjiefeng");
      cq.where(username);
      List users = session.createQuery(cq).getResultList();

      for(int i = 0 ; i < users.size() ; i++)
      {
        User u = (User)users.get(i);
        System.out.println(u.toString());
      }
      ts.commit();
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }
  }

  //3.条件查询2，查询年龄在30-40的User
  public void testWhere2QueryUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();

      CriteriaBuilder builder = session.getCriteriaBuilder();
      CriteriaQuery<User> cq = builder.createQuery(User.class);
      Root<User> root = cq.from(User.class);
      Predicate age1 = builder.ge(root.get("age"),30);
      Predicate age2 = builder.le(root.get("age"),40);
      cq.where(builder.and(age1,age2));
      List users = session.createQuery(cq).getResultList();

      for(int i = 0 ; i < users.size() ; i++)
      {
        User u = (User)users.get(i);
        System.out.println(u.toString());
      }
      ts.commit();
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }
  }

  //4.条件查询3,名字带有lin的人
  public void testWhere3QueryUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      CriteriaBuilder builder = session.getCriteriaBuilder();
      CriteriaQuery<User> cq = builder.createQuery(User.class);
      Root<User> root = cq.from(User.class);
      //创建查询条件
      Predicate username = builder.like(root.get("name"),"%lin%");
      cq.where(username);
      List users = session.createQuery(cq).getResultList();
      for(int i = 0 ; i < users.size() ; i++)
      {
        User u = (User)users.get(i);
        System.out.println(u.toString());
      }
      ts.commit();
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }
  }

  //5.条件查询4，名字带有lin的小于18岁的男性
  public void testWhere4QueryUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      CriteriaBuilder builder = session.getCriteriaBuilder();
      CriteriaQuery<User> cq = builder.createQuery(User.class);
      Root<User> root = cq.from(User.class);
      //创建查询条件
      Predicate username = builder.like(root.get("name"),"%lin%");
      Predicate gender = builder.equal(root.get("gender"), "男");
      Predicate age = builder.lt(root.get("age"), 18);
      cq.where(builder.and(username, builder.and(gender, age)));
      List users = session.createQuery(cq).getResultList();
      for(int i = 0 ; i < users.size() ; i++)
      {
        User u = (User)users.get(i);
        System.out.println(u.toString());
      }
      ts.commit();
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }
  }

  //6.条件查询5，查询年龄包含lin的男性且年龄小于18的User,年龄由小到大
  public void testWhere5QueryUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();

      CriteriaBuilder builder = session.getCriteriaBuilder();
      CriteriaQuery<User> cq = builder.createQuery(User.class);
      Root<User> root = cq.from(User.class);
      //创建查询条件
      Predicate username = builder.like(root.get("name"),"%lin%");
      Predicate gender = builder.equal(root.get("gender"), "男");
      Predicate age = builder.lt(root.get("age"), 18);
      cq.where(builder.and(username, builder.and(gender, age)));
      cq.orderBy(builder.desc(root.get("age"))); //asc：升序

      List users = session.createQuery(cq).getResultList();
      for(int i = 0 ; i < users.size() ; i++)
      {
        User u = (User)users.get(i);
        System.out.println(u.toString());
      }
      ts.commit();
    }catch (Exception e){
      e.printStackTrace();
      if(ts!=null){
        ts.rollback();
      }
    }
  }

  //7.条件查询6，查询两个或者多个属性
  public void testSeveralAttributesQueryUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf(); //sessionfactory单态模式
      session = sf.getCurrentSession();  //保证每个读写线程有唯一的session实例
      ts = session.beginTransaction();
      CriteriaBuilder cb = session.getCriteriaBuilder();
      CriteriaQuery<Object[]> cq = cb.createQuery(Object[].class);
      Root<User> root = cq.from(User.class);
      //创建查询条件
      cq.multiselect(root.get("age"), root.get("gender"));
      Query query = session.createQuery(cq);
      List users = session.createQuery(cq).getResultList();

      for(int i = 0 ; i < users.size() ; i++)
      {
        Object[] objs = (Object[])users.get(i);
        System.out.println(objs[1] + " " + objs[0]);
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

  //8.条件查询7，分组查询
  public void testGroupQueryUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf(); //sessionfactory单态模式
      session = sf.getCurrentSession();  //保证每个读写线程有唯一的session实例
      ts = session.beginTransaction();
      CriteriaBuilder cb = session.getCriteriaBuilder();
      CriteriaQuery<Object[]> cq = cb.createQuery(Object[].class);
      Root<User> root = cq.from(User.class);
      //创建查询条件
      cq.multiselect(root.get("gender"), cb.avg(root.get("age")));
      cq.groupBy(root.get("gender"));
      Query query = session.createQuery(cq);
      List users = session.createQuery(cq).getResultList();

      for(int i = 0 ; i < users.size() ; i++)
      {
        Object[] objs = (Object[])users.get(i);
        System.out.println(objs[0] + " " + objs[1]);
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

  //9.条件查询8，统计查询
  public void testStatisticalQueryUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf(); //sessionfactory单态模式
      session = sf.getCurrentSession();  //保证每个读写线程有唯一的session实例
      ts = session.beginTransaction();
      CriteriaBuilder builder = session.getCriteriaBuilder();
      CriteriaQuery<Number> cq = builder.createQuery(Number.class);
      Root<User> root = cq.from(User.class);
      //创建查询条件
      cq.select(builder.avg(root.get("age")));
      Query query = session.createQuery(cq);
      Number result = (Number)query.getSingleResult();
      System.out.println(result);
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

}
