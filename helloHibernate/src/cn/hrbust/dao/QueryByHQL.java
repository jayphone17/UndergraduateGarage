package cn.hrbust.dao;

import cn.hrbust.pojo.User;
import junit.framework.TestCase;
import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import java.lang.module.Configuration;
import java.util.Iterator;
import java.util.List;

public class QueryByHQL extends TestCase {

  //基本HQL查询方法
  public void testQueryUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      Query query = session.createQuery("from User");
      List<User> users = query.list();

      //方式1，for each
      for (User u : users){
        System.out.println(u.getId()+" "+u.getName()+" "+u.getAge());
      }
      //方式2，使用迭代器
//      Iterator iterator = users.iterator();
//      while(iterator.hasNext()){
//        User u = (User) iterator.next();
//        System.out.println(u.getId()+" "+u.getName()+" "+u.getAge());
//      }
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

  //查询类的一个属性
  public void testQueryUserOneAttributes(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      Query query = session.createQuery("select u.name from User u");
      List names = query.list();

      for(int i = 0 ; i<names.size() ; i++){
        String name = (String) names.get(i);
        System.out.println(name);
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

  //查询类的多个属性
  public void testQueryUserSeveralAttributes(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      Query query = session.createQuery("select u.name,u.age,u.gender from User u");
      List attributes = query.list();

      for(int i = 0 ; i<attributes.size() ; i++){
        Object objs[] = (Object[]) attributes.get(i);
        System.out.println(objs[0]+" 的年龄是："+objs[1]+" 性别是："+objs[2]);
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

  //用distinct去重
  public void testQueryUserOneAttributesByDistinct(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      Query query = session.createQuery("select distinct u.name from User u");
      List names = query.list();

      for(int i = 0 ; i<names.size() ; i++){
        String name = (String) names.get(i);
        System.out.println(name);
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

  //实例化查询
  public void testQueryUserOneAttributesByExample(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      Query query = session.createQuery("select new User(u.name,u.age) from User u");
      List<User> users= query.list();
      for(int i = 0 ; i<users.size() ; i++){
        User u = users.get(i);
        System.out.println(u.getName()+" 的年龄是 "+u.getAge());
        if (u.getAge() == 11)
        {
          session.saveOrUpdate(u);
          //此时u是瞬时对象
        }
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

  //统计查询
  public void testStatisticalQuery(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      //统计有多少条数据库记录
      Query query = session.createQuery("select count(*) from User u");
      Number result = (Number) query.uniqueResult();
      System.out.println(result);
      //统计平均年龄
      query = session.createQuery("select avg (age) from User u");
      Number result1 = (Number) query.uniqueResult();
      System.out.println(result1);
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

  //条件查询1,查询名字linjiefeng
  public void testQueryUserByWhere111(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      Query query = session.createQuery("from User u  where u.name = 'linjiefeng'");
      List<User> users= query.list();
      for (User u : users){
        System.out.println(u.getId()+" "+u.getName()+" "+u.getAge());
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

  //条件查询2，测试字段是否在指定的范围之内，查询年龄在20-30之间
  public void testQueryUserByWhere222(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      //语句1
      //Query query = session.createQuery("from User u  where u.age between 20 and 30");
      //语句2
      Query query = session.createQuery("from User u  where u.age>=20 and u.age<=30");
      List<User> users= query.list();
      for (User u : users){
        System.out.println(u.getId()+" "+u.getName()+" "+u.getAge());
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

  //条件查询3，模糊查询，查询名字中含有"jay"的对象
  public void testQueryUserByWhere333(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      Query query = session.createQuery("from User u  where u.name like '%jay%' ");
      List<User> users= query.list();
      for (User u : users){
        System.out.println(u.getId()+" "+u.getName()+" "+u.getAge());
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

  //条件查询4，嵌套的条件子查询
  //查询年龄>平均年龄的对象
  public void testEmbededSonQuery(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      Query query = session.createQuery("from User u  where u.age > (select avg (u.age) from User u) ");
      List<User> users= query.list();
      for (User u : users){
        System.out.println(u.getId()+" "+u.getName()+" "+u.getAge());
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

  //基本查询，OrderBy
  //按照年龄降序，年龄相同按照名字升序
  public void testQueryByOrderBy(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      Query query = session.createQuery("from User u order by u.age desc ,u.name ");
      List<User> users= query.list();
      for (User u : users){
        System.out.println(u.getId()+" "+u.getName()+" "+u.getAge());
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

  //统计男生女生的平均年龄
  public void testQueryByGroup(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      Query query = session.createQuery("select u.gender,avg(u.age) from User u group by u.gender ");
      List<Object[]> ans= query.list();
      for(int i=0;i<ans.size();i++){
        Object[] objs = ans.get(i);
        System.out.println(objs[0]+" 的平均年龄为：" + objs[1]);
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

  //结合having语句，对查询结果进行一个限制
  //可以对每组进行条件限制
  //select u.gender,avg(u.age) from User u group by (select age from User u where avg(u.age)>11 )

  //使用" ？"占位符，使用query的set方法进行参数绑定
  public void testQueryUserByParameter(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      Query query = session.createQuery("from User u where u.name=? ");
      //query.setString(0,"linjiefeng");
      //hibernate5.2 setString 已经被废弃了
      //替代方法就是setParameter方法
      query.setParameter(0,"lnijiefeng");
      List<User> users= query.list();
      for (User u : users){
        System.out.println(u.getId()+" "+u.getName()+" "+u.getAge());
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

  //分页查询
  public void testQueryByPage(){
    QueryByPage(3);
  }

  public void QueryByPage(int pageSize){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      Query query = session.createQuery("select count(*) from User u  ");
      Number cnts = (Number) query.uniqueResult();
      int userCount = cnts.intValue();
      int pageCount = userCount/pageSize;
      if(userCount%pageSize != 0){
        pageCount++;
      }
      Query query1 = session.createQuery("from User u  ");
      for(int i=0;i<pageCount;i++){
        System.out.println("第 "+i+" 页: ");
        System.out.println("--------------------------");
        query1.setFirstResult(i*pageSize);
        query1.setMaxResults(pageSize);
        List<User> us= query1.getResultList();
        for(User u : us){
          System.out.println(u.getId()+" "+u.getName()+" "+u.getAge());
        }
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

  //User.hbm.xml定义命名查询标签
//  public void testQueryUserByTag(){
//    Configuration cfg = null;
//    SessionFactory sf = null;
//    Session session = null;
//    Transaction ts = null;
//    try {
//      sf = HibernateUtil.getSf();
//      session = sf.getCurrentSession();
//      ts = session.beginTransaction();
//
//      ts.commit();
//    }catch (Exception e){
//      e.printStackTrace();
//      if(ts!=null){
//        ts.rollback();
//      }
//    }finally {
//      //session.close();
//      //sf.close();
//    }
//  }

  //更新对象
  public void testUpdate(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      Query query = session.createQuery("update User u set u.name = 'update成功' where u.name='linjiefeng' ");
      query.executeUpdate();
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

  //删除对象
  //删除"保存对象"
  public void testDelete(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf();
      session = sf.getCurrentSession();
      ts = session.beginTransaction();
      Query query = session.createQuery("delete User u where u.name='保存对象' ");
      query.executeUpdate();
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


}
