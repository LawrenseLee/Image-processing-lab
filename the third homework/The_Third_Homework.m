clear all;
close all��
var=0;
N=18; 
m=0;
n=0;
pi=0;
pj=0;
%����ͼ�񲿷�
    for i=0:N
       if(i<10)
          filename=sprintf('00%d.bmp',i);         %������Ҫ������ļ�����
       else                               %����Ӧ���ļ�����ڹ���Ŀ¼��
          filename=sprintf('0%d.bmp',i);          %������Ҫ������ļ�
       end
       I=imread(filename);                        %����ͼƬ�ļ�
       Im{i+1}=I;                     
    end                                    
       [m n]=size(I);                             %��ȡ�����������                                          
    for i=0:N
       IM{i+1}=im2bw(Im{i+1});           %ͼ���ֵ��
       i=i+1;                                     
     end
for i=0:N
    subplot(1,N+1,i+1)                            
    imshow(Im{i+1});                              %��ʾû�о�������ʱ������
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
                                              %ͨ���в����ֵ����ж�
                pi=i;                             %���λ�õ�ͼƬ���
                pj=j;                             %�ұ�λ�õ�ͼƬ���
              end   
          end
        end
    end
    res(i+1,:)=[pi pj var];                   
end
res                                       %��ʾ�Ľ��Ϊ�����λ��ͼƬ��ţ��ұ�λ��ͼƬ��ţ�����ֵ
k=0;
for i=0:N
    if(res(i+1,3)==0)                        %�����Ϊ0�ı�ŷ�����ǰ��
        sq(k+1)=res(i+1,2);
    end
end
for i=0:N-1
    for j=0:N
      if(sq(i+1)==res(j+1,1))                 
          sq(i+2)=res(j+1,2);                     %�����н�������
      end
    end
end
sq                                                %��ʾ���е�˳��
ResIm=Im{sq(1)+1};
for i=1:N
    ResIm=[ResIm,Im{sq(i+1)+1}];           %��ͼƬ�ȱ�Ű�˳�����ƴ��
end
hold off
imshow(ResIm)                                     %��ʾͼƬƴ�ӽ��
