package cn.hrbust.dao;

import cn.hrbust.pojo.Card;
import cn.hrbust.pojo.User;
import junit.framework.TestCase;
import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

import java.lang.module.Configuration;
import java.sql.Date;
import java.util.List;

public class Association_Mapping_1_VS_1 extends TestCase {
  //保存
  public void testSaveUserAndIdCard(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    Card card = new Card();
    card.setInfo("关联保存对象888");
    User user  = new User();
    user.setName("外键关联双向一对一");
    user.setAge(666);
    user.setGender("female");
    user.setBirthday(Date.valueOf("1666-6-6"));
    card.setUser(user);
    user.setCard(card);
    try {
      sf = HibernateUtil.getSf(); //session factory单态模式
      session = sf.getCurrentSession();  //保证每个读写线程有唯一的session实例
      ts = session.beginTransaction();
      session.save(card);
      //一对一关联映射参考另一方主键的对象会自动级联
      //session.save(user);
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

  //级联查询
  public void testQueryUserAndIdCardInfo(){
    Configuration cfg = null;
    SessionFactory sf = null;
    Session session = null;
    Transaction ts = null;
    try {
      sf = HibernateUtil.getSf(); //session factory单态模式
      session = sf.getCurrentSession();  //保证每个读写线程有唯一的session实例
      ts = session.beginTransaction();

      Query query = session.createQuery("from Card");
      List<Card> cards = query.getResultList();
      for(Card c : cards){
        System.out.println(c.getUser().getId()+" : "+c.getInfo());
      }
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
