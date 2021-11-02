package cn.tf.lessontype.dao;
import cn.tf.base.BaseDao;
import cn.tf.lessontype.domain.CrmLessontype;

import java.util.List;

public interface  LessontypeDao  extends BaseDao<CrmLessontype>{
  //增
  void save (CrmLessontype crmLessontype);
  //删
  void delete(CrmLessontype crmLessontype);
  //改
  void update(CrmLessontype crmLessontype);
  //查
  public List<CrmLessontype> findAll(String lessonTypeID);
}
