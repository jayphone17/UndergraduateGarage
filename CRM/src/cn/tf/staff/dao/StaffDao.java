package cn.tf.staff.dao;

import java.util.List;

import cn.tf.staff.domain.CrmStaff;

public interface StaffDao {
  //增
  void save(CrmStaff crmStaff);
  //删
  void delete(CrmStaff crmStaff);
  //改
  void update(CrmStaff crmStaff);
  //查
  CrmStaff find(String loginName, String loginPwd);

  List<CrmStaff> findAllStaff(String condition, Object[] params);

  CrmStaff findById(String staffId);
}
