package cn.tf.post.dao;

import java.util.List;

import cn.tf.base.BaseDao;
import cn.tf.department.domain.CrmDepartment;
import cn.tf.post.domain.CrmPost;
import cn.tf.staff.domain.CrmStaff;

public interface PostDao extends  BaseDao<CrmPost>{
  //增
  void save(CrmPost crmPost);
  //删
  void delete(CrmPost crmPost);
  //改
  void update(CrmPost crmPost);
  //查
  public List<CrmPost> findAll(String departmentId);
}
