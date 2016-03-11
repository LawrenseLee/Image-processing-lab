clear all;
close all；
var=0;
N=18; 
m=0;
n=0;
pi=0;
pj=0;
%导入图像部分
    for i=0:N
       if(i<10)
          filename=sprintf('00%d.bmp',i);         %构造需要导入的文件名字
       else                               %而相应的文件存放在工作目录中
          filename=sprintf('0%d.bmp',i);          %构造需要导入的文件
       end
       I=imread(filename);                        %导入图片文件
       Im{i+1}=I;                     
    end                                    
       [m n]=size(I);                             %提取矩阵的行与列                                          
    for i=0:N
       IM{i+1}=im2bw(Im{i+1});           %图像二值化
       i=i+1;                                     
     end
for i=0:N
    subplot(1,N+1,i+1)                            
    imshow(Im{i+1});                              %显示没有经过处理时候的情况
end
%}
for i=0:N
    var=-1;
    for j=0:N
        if(i~=j)
          if(var==-1)
            var=sum(abs(IM{i+1}(:,72)-IM{j+1}(:,1)));
            pi=i;
            pj=j;
          else if(sum(abs(double(IM{i+1}(:,72))-double(IM{j+1}(:,1))))<var)  
                var=sum(abs(double(IM{i+1}(:,72))-double(IM{j+1}(:,1))));    
                                              %通过残差绝对值求和判断
                pi=i;                             %左边位置的图片编号
                pj=j;                             %右边位置的图片编号
              end   
          end
        end
    end
    res(i+1,:)=[pi pj var];                   
end
res                                       %显示的结果为：左边位置图片编号，右边位置图片编号，距离值
k=0;
for i=0:N
    if(res(i+1,3)==0)                        %将误差为0的编号放在最前面
        sq(k+1)=res(i+1,2);
    end
end
for i=0:N-1
    for j=0:N
      if(sq(i+1)==res(j+1,1))                 
          sq(i+2)=res(j+1,2);                     %对序列进行排序
      end
    end
end
sq                                                %显示排列的顺序
ResIm=Im{sq(1)+1};
for i=1:N
    ResIm=[ResIm,Im{sq(i+1)+1}];           %将图片比编号按顺序进行拼接
end
hold off
imshow(ResIm)                                     %显示图片拼接结果
