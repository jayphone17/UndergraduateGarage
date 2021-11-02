//
// Source code recreated from a .class file by IntelliJ IDEA
// (powered by Fernflower decompiler)
//

package com.ascent.daoImpl;

import com.ascent.dao.UnitDao;
import com.ascent.pojo.Unit;
import java.sql.SQLException;
import java.util.List;
import org.hibernate.HibernateException;
import org.hibernate.Query;
import org.hibernate.Session;
import org.springframework.orm.hibernate3.HibernateCallback;
import org.springframework.orm.hibernate3.support.HibernateDaoSupport;

public class UnitDaoImpl extends HibernateDaoSupport implements UnitDao {
  public UnitDaoImpl() {
  }

  public void addUnit(Unit unit) {
    this.getHibernateTemplate().save(unit);
  }

  public void deleteUnit(Unit unit) {
    this.getHibernateTemplate().delete(unit);
  }

  public List<Unit> findAllUnit(final int pagno, final int maxrows) {
    return (List)this.getHibernateTemplate().execute(new HibernateCallback() {
      public Object doInHibernate(Session session) throws HibernateException {
        Query query = session.createQuery("from Unit u order by u.uid desc");
        query.setFirstResult((pagno - 1) * maxrows);
        query.setMaxResults(maxrows);
        List list = query.list();
        return list;
      }
    });
  }

  public Unit findUnitById(Integer id) {
    Unit unit = (Unit)this.getHibernateTemplate().load(Unit.class, id);
    unit.getProjects().add("测试");
    unit.getUser().getPassword();
    unit.getUnitname();
    return unit;
  }

  public int getTotalCount() {
    List count = this.getHibernateTemplate().find("select count(u.unitid) from Unit u");
    return (Integer)count.get(0);
  }

  public void updateUnit(Unit unit) {
    this.getHibernateTemplate().update(unit);
  }
}
