%% Constantes a alterar.....

OPTION = 1; 

% 0-> Pior caso (encontrar a imagem)
% 1-> Pior caso (nao encontrar a imagem)
% 2-> Melhor caso (encontrar a imagem)
% 3-> Melhor caso (nao encontrar a imagem)

% Size -> largura da imagem grande (sendo a imagem quadrada) 
size_min = 50;
size_inc = 1;
size_max = 100; % w = h

% Size -> largura da imagem pequena (sendo a imagem quadrada) 
size_fix = 60;

printAll = 1;

colorV1 = "o-";

% Executar e ler dados
% generate the file text with data
status = system(sprintf("./execute_locateTests.sh %d %d %d %d %d %d",OPTION,size_fix,size_min,size_inc,size_max)); 
customLabelx = "Numero de pixeis da imagem";
if OPTION == 0
    customLegend = sprintf("Pior caso (imagem encontrada) - s%dx%d",size_fix,size_fix);
    path = "bySize/worstCaseFound";
elseif OPTION == 1
    customLegend = sprintf("Pior caso (imagem nao encontrada) - s%dx%d",size_fix,size_fix);
    path = "bySize/worstCaseNotFound";
elseif OPTION == 2
    customLegend = sprintf("Melhor caso (imagem encontrada) - s%dx%d",size_fix,size_fix);
    path = "bySize/bestCaseFound";
elseif OPTION == 3
    customLegend = sprintf("Melhor caso (imagem nao encontrada) - s%dx%d",size_fix,size_fix);
    path = "bySize/bestCaseNotFound";
end

file = fopen("data_locateTests.txt","r");
formatSpec = '%d %f %f %d %d %d';
data = textscan(file, formatSpec);
fclose(file);

nPixelsArray = double(data{1});
timeArray = double(data{2}); 
caltimeArray = double(data{3});
PIXMEMArray = double(data{4}); 
COMPARISONSArray = double(data{5}); 
OPERATIONSArray = double(data{6}); 

%% Tempo de execucao em funcao de n
f1_time = figure(1);

plot(nPixelsArray,timeArray,colorV1,'DisplayName',sprintf("%s",customLegend));
hold on;

grid on
title("Tempo de execucao em funcao de n")
xlabel(customLabelx)
ylabel("Tempo de execucao (segundos)")
legend

if printAll
  f1_time.PaperType='A4';
  f1_time.PaperOrientation='landscape';
  f1_time.PaperUnits='points';
  print(sprintf("%s/time/time_S%dx%d_s%dx%d.pdf",path,size_max,size_max,size_fix,size_fix),'-dpdf','-noui','-fillpage');
end

%% Numero de comparacoes em funcao de n
f2_comparisons = figure(2);

plot(nPixelsArray,COMPARISONSArray,colorV1,'DisplayName',sprintf("%s",customLegend));
hold on;

grid on
title("Numero de comparacoes em funcao de n")
xlabel(customLabelx)
ylabel("Numero de comparacoes (COMPARISONS)")
legend

if printAll
  f2_comparisons.PaperType='A4';
  f2_comparisons.PaperOrientation='landscape';
  f2_comparisons.PaperUnits='points';
  print(sprintf("%s/comparisons/comparisons_S%dx%d_s%dx%d.pdf",path,size_max,size_max,size_fix,size_fix),'-dpdf','-noui','-fillpage');
end
