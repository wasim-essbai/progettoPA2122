clear
clc
dim_cat_data = 100;
dim_dog_data = 150;

%Cat data generation
cat_weight_avg = 4;
cat_height_avg = 25;
cat_weight_std = sqrt((3.6 - cat_weight_avg)^2 + (4.5 - cat_weight_avg)^2);
cat_height_std = sqrt((23 - cat_height_avg)^2 + (25 - cat_height_avg)^2);
random_cat_weights = randn(dim_cat_data,1)*cat_weight_std + cat_weight_avg;
random_cat_heights = randn(dim_cat_data,1)*cat_height_std + cat_height_avg;
cat_dataset = zeros(dim_cat_data,3);
cat_dataset(:,1) = round(random_cat_weights,2);
cat_dataset(:,2) = round(random_cat_heights,2);

%Dog data generation
dog_weight_avg = 21.5;
dog_height_avg = 62.5;
dog_weight_std = sqrt((5 - dog_weight_avg)^2 + (10 - dog_weight_avg)^2 + (25 - dog_weight_avg)^2 + (45 - dog_weight_avg)^2)/2;
dog_height_std = sqrt((15 - dog_height_avg)^2 + (110 - dog_height_avg)^2)/2;
random_dog_weights = randn(dim_dog_data,1)*dog_weight_std + dog_weight_avg;
random_dog_heights = randn(dim_dog_data,1)*dog_height_std + dog_height_avg;
dog_dataset = ones(dim_dog_data,3);
dog_dataset(:,1) = round(random_dog_weights,2);
dog_dataset(:,2) = round(random_dog_heights,2);

dataset = [dog_dataset; cat_dataset]

writematrix(dataset,'dataset.txt','Delimiter',' ')  

