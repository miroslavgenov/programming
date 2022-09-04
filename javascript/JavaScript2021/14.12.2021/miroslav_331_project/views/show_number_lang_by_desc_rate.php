<?php require_once(PATH.'\\views\\head.php') ?>
<h4>First <?=$param?> Langs</h4>
<?php foreach($languages as $el):?>
    <tr>
        <td><?=$el['id']?></td>
        <td><?=$el['language']?></td>
        <td><?=$el['creator']?></td>
        <td><?=$el['dateCreated']?></td>
        <td><?=$el['Rate2021']?></td>
            </tr>
            <?php endforeach;?>    
<?php require_once(PATH.'\\views\\foot.php') ?>
