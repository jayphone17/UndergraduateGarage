package cn.hrbust.dao;

import org.hibernate.boot.Metadata;
import org.hibernate.boot.MetadataSources;
import org.hibernate.boot.registry.StandardServiceRegistryBuilder;
import org.hibernate.tool.hbm2ddl.SchemaExport;
import org.hibernate.tool.schema.TargetType;

import javax.imageio.spi.ServiceRegistry;
import java.util.EnumSet;

public class ExportSchema {

	public static void main(String[] args) {
		ServiceRegistry sr = (ServiceRegistry) new StandardServiceRegistryBuilder().configure().build();
		Metadata metadata = new MetadataSources((org.hibernate.service.ServiceRegistry) sr).buildMetadata();
		//创建Schema表的对象，目的是根据数据生成表
		SchemaExport se = new SchemaExport();
		se.create(EnumSet.of(TargetType.DATABASE), metadata);
	}

}
