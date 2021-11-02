package cn.tf.base;

import java.io.Serializable;
import java.util.List;

import org.hibernate.criterion.DetachedCriteria;

//通用dao接口
public interface BaseDao<T> {
	//增
	public void save(T t);
  //删
  public void delete(T t);
	//改
	public void update(T t);
  //查询所有
  public List<T>  findAll();
	//保存或更新
	public void SaveOrUpdate(T t);
	//条件查询
	public List<T>  findAll(String condition,Object...  params);

	//离线查询
	public List<T>  findAll(DetachedCriteria  detachedCriteria);

	//分页
	public List<T>  findAllByPage(int startIndex,int pageSize);

	//分页的总记录数
	public int getTotalRecode();
	//查找
	T findById(Serializable  serializable);


}
