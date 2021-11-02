package cn.hrbust.dao;
import cn.hrbust.pojo.Group;
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

public class Association_Mapping_n_VS_1单向 extends TestCase {
  //1.基本SQL查询,通过标签进行查询
  public void testQueryUser(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf(); //sessionfactory单态模式
      session = sf.getCurrentSession();  //保证每个读写线程有唯一的session实例
      ts = session.beginTransaction();
      NativeQuery nq = session.createNativeQuery("select * from T_USER u where u.age > 40", User.class);
      List users = nq.getResultList();
      for(int i = 0 ; i < users.size() ; i++)
      {
        User u = (User)users.get(i);
        System.out.println(u.toString());
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

  //2.基本的SQL查询，查询所有属性
  public void testQueryUserByTag(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf(); //sessionfactory单态模式
      session = sf.getCurrentSession();  //保证每个读写线程有唯一的session实例
      ts = session.beginTransaction();
      Query sqlQuery = session.getNamedQuery("QueryUsers");
      List users = sqlQuery.getResultList();
      for(int i = 0 ; i < users.size() ; i++)
      {
        User u = (User)users.get(i);
        System.out.println(u.toString());
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

//  //3.保存瞬时用户对象和组织
  public void testSaveUserAndGroup(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    Group g = new Group();
    g.setName("软件工程");
    User u = new User();
    u.setName("王五");
    u.setGender("男");
    u.setAge(33);
    u.setBirthday(Date.valueOf("2001-1-1"));
    u.setName("赵六");
    u.setGroup(g);
    try {
      sf = HibernateUtil.getSf(); //sessionfactory单态模式
      session = sf.getCurrentSession();  //保证每个读写线程有唯一的session实例
      ts = session.beginTransaction();
      session.save(g);
      session.save(u);
      ts.commit();
      u.setName("王五");  //事务提交后，Sess ion关闭，属性改变，此时的对象的属性变化不会发送update语句

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

  //4.级联（一起）保存用户对象和组织
  public void testCascadeSaveUserAndGroup(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;

    Group group = new Group();
    group.setName("Cascading");

    User user = new User();
    user.setName("测试级联no.2");
    user.setGender("female");
    user.setAge(20);
    user.setBirthday(Date.valueOf("2000-5-11"));
    user.setGroup(group);

    try {
      sf = HibernateUtil.getSf(); //session factory单态模式
      session = sf.getCurrentSession();  //保证每个读写线程有唯一的session实例
      ts = session.beginTransaction();

      session.save(user);
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
